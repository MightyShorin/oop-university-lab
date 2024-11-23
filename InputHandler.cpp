//
// Created by Сергей Шорин on 21.10.2024.
//

#include "InputHandler.h"


void InputHandler::getParameters(size_t &frequency, size_t &speed, size_t &line_len, bool &epilepsia) {

    std::count << "Введите частоту появления линии (1-30): ";
    while (true) {
        std::cin >> frequency; // пытаемся считать целое число
        if (std::cin.fail() || frequency < 1 || frequency > 30) {  // если ввод не удался или число не в диапазоне
            std::cin.clear(); // Сбрасываем состояние ошибки, если ввведено не целое число, чтобы cin дальше работал
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем неверный ввод
            std::cout << "Ошибка: частота должна быть целым числом от 1 до 30. Попробуйте снова: ";
        } else {
            break; // Ввод корректен
        }
    }

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