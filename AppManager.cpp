//
// Created by Сергей Шорин on 20.10.2024.
//

#include "AppManager.h"
#include "Terminal.h"
#include "InputHandler.h"
#include <iostream>
#include <thread>
#include <chrono>

AppManager::AppManager(bool epilepsia, size_t line_len, size_t speed, size_t frequency)
    : epilepsia(epilepsia), line_len(line_len), speed(speed), frequency(frequency) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // Инициализация генератора случайных чисел
}

void AppManager::inputParameters() {
    InputHandler::getParameters(frequency, speed, line_len, epilepsia);
}

void AppManager::run() {
    Terminal::clearScreen();  // Очистка экрана

    Terminal::getSize(term_width, term_height);  // Получение размеров терминала

    const size_t time_point_min = 0;
    const size_t time_point_max = 1000;
    std::unordered_map<size_t, std::vector<Line>> time_lines; // хранение живых линий по времени (игра слов)

    std::set<size_t> unique_keys; // нам нужны уникальные времена

    while (unique_keys.size() < frequency) {
        size_t random_time_point = time_point_min + std::rand() % (time_point_max - time_point_min + 1); // формула подходит под любой диапазон
        unique_keys.insert(random_time_point);
    }

    // Заполняем unordered_map
    for (const auto& key : unique_keys) {
        time_lines[key] = {}; // пока пустуют, грусть, печаль
    }

    const size_t period_check = 1000;  // Период в миллисекундах

    auto start_time = std::chrono::system_clock::now();  // время начала цикла
    while (true) {
        auto current_time = std::chrono::system_clock::now();  // обновляем постоянно
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();  // сколько прошло времени с начала цикла

        size_t time_in_period = elapsed_time % period_check;  // отбросим секунды, оставим только миллисекунды

        // Проверяем каждый таймпоинт
        for (const auto& [time_point, _] : time_lines) {  // распаковка пары, значение в данном коде нам не нужно
            if (time_in_period == time_point) {
                time_lines[time_point].emplace_back(line_len, term_height, epilepsia);  // создаём новую линию в векторе
                performAction(time_point, time_lines);  // передаем ссылочку на unordered_map
            }
        }
        // Задержка, чтобы не перегружать CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

    // while (true) {
    //     Line line(line_len, term_height, epilepsia);
    //     line.setStartXY(std::rand() % term_width + 1, 1); // Установка начальной позиции линии
    //
    //     // Переменная для отслеживания оставшихся шагов змейки
    //     size_t steps = term_height + line_len;
    //
    //     while (steps > 0) {
    //         line.move();
    //         std::this_thread::sleep_for(std::chrono::milliseconds(1000 / speed));
    //         steps--;  // Уменьшаем количество оставшихся шагов
    //     }
    // }

void AppManager::performAction(size_t time_point, std::unordered_map<size_t, std::vector<Line>>& time_lines) {
    auto& lines = time_lines[time_point];  // Ссылка на вектор
    lines.back().setStartXY(2 + std::rand() % (term_width - 2), 1);  // Установка начальной позиции новой линии

    // используем итератор, так как удаляем элементы во время цикла
    for (auto it = lines.begin(); it != lines.end(); ) {
        it->move();
        if (it->getLenOnScreen() == line_len) {
            it = lines.erase(it);  // Удаление и обновление итератора
        } else {
            ++it;  // Переход к следующему элементу
        }
    }
}