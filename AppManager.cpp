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

    size_t  term_width, term_height;
    Terminal::getSize(term_width, term_height);  // Получение размеров терминала

    while (true) {
        // Бесконечный цикл для создания новых змей
        Line line(line_len, term_height, epilepsia);
        line.setStartXY(std::rand() % term_width + 1, 1); // Установка начальной позиции линии
        // line.setColorMode(epilepsia);

        Line line2(line_len, term_height, epilepsia);
        line2.setStartXY(std::rand() % term_width + 1, 1); // Установка начальной позиции линии
        // line2.setColorMode(epilepsia);

        // Переменная для отслеживания оставшихся шагов змейки
        size_t steps = term_height + line_len;


        while (steps > 0) {
            line.move();
            line2.move();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / speed));
            steps--;  // Уменьшаем количество оставшихся шагов
        }
    }
}