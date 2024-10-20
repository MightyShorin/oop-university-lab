//
// Created by Сергей Шорин on 20.10.2024.
//

#include "AppManager.h"

#include <iostream>
#include <thread>
#include <chrono>

AppManager::AppManager(bool epilepsia_mode, size_t line_len, size_t speed)
    : epilepsia(epilepsia_mode), line_len(line_len), speed(speed) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // Инициализация генератора случайных чисел
}

void AppManager::getTerminalSize(size_t &width, size_t &height) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col;   // Ширина терминала
    height = w.ws_row;  // Высота терминала
}

void AppManager::inputParameters() {
    std::cout << "Введите скорость (1-30): ";
    while (true) {
        std::cin >> speed;
        if (std::cin.fail() || speed < 1 || speed > 30) {
            std::cin.clear(); // Сбрасываем состояние ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем неверный ввод
            std::cout << "Ошибка: скорость должна быть целым числом от 1 до 30. Попробуйте снова: ";
        } else {
            break; // Ввод корректен
        }
    }

    std::cout << "Введите длину линии (1-30): ";
    while (true) {
        std::cin >> line_len;
        if (std::cin.fail() || line_len < 1 || line_len > 30) {
            std::cin.clear(); // Сбрасываем состояние ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем неверный ввод
            std::cout << "Ошибка: длина линии должна быть целым числом от 1 до 30. Попробуйте снова: ";
        } else {
            break; // Ввод корректен
        }
    }

    std::cout << "Включить режим эпилепсии? (Y/N): ";
    char input;
    while (true) {
        std::cin >> input;
        if (input == 'Y' || input == 'y') {
            epilepsia = true;
            break;
        } else if (input == 'N' || input == 'n') {
            epilepsia = false;
            break;
        } else {
            std::cout << "Ошибка: введите 'Y' для включения или 'N' для выключения. Попробуйте снова: ";
        }
    }
}

void AppManager::run() {
    std::cout << "\033[2J";  // Очистка экрана

    size_t  term_width, term_height;
    getTerminalSize(term_width, term_height);  // Получение размеров терминала

    while (true) {
        // Бесконечный цикл для создания новых змей
        Line line(line_len, term_height);
        line.setStartXY(std::rand() % term_width + 1, 1); // Установка начальной позиции линии
        line.setColor(epilepsia);

        // Переменная для отслеживания оставшихся шагов змейки
        size_t steps = term_height + line_len;


        while (steps > 0) {
            line.draw();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / speed));
            steps--;  // Уменьшаем количество оставшихся шагов
        }
    }
}