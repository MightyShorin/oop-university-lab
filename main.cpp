#include "AppManager.h"
#include <iostream>
#include <cstdlib>
#include <string>

void printHelp() {
    std::cout << "Использование: программа [скорость] [длина линии] [эпилепсия]\n";
    std::cout << "где:\n";
    std::cout << "  скорость - целое число от 1 до 30\n";
    std::cout << "  длина линии - целое число от 1 до 30\n";
    std::cout << "  эпилепсия - 'Y' (включить режим эпилепсии) или 'N' (выключить)\n";
}

int main(int argc, char* argv[]) {
    // Проверка на -h для помощи
    if (argc >= 2 && std::string(argv[1]) == "--help") {
        printHelp();
        return 0;
    }

    // Проверка на количество аргументов
    if (argc != 4 && argc != 1) {
        std::cout << "Ошибка: Ожидается три аргумента. Введите --help" << std::endl;
        return 1;
    }

    size_t speed = 5;
    size_t line_len = 5;
    bool epilepsia = true;

    if (argc == 1) {
        AppManager app(epilepsia, line_len, speed);
        app.inputParameters(); // Ввод параметров только если аргументы не были переданы
        app.run();
        return 0;
    }

    // Проверка первого аргумента
    try {
        speed = std::stoi(argv[1]);
        if (speed < 1 || speed > 30) {
            std::cout << "Ошибка: скорость должна быть целым числом от 1 до 30. Введите --help" << std::endl;
            return 1;
        }
    } catch (std::invalid_argument&) {
        std::cout << "Ошибка: скорость должна быть целым числом от 1 до 30. Введите --help" << std::endl;
        return 1;
    }

    // Проверка второго аргумента
    try {
        line_len = std::stoi(argv[2]);
        if (line_len < 1 || line_len > 30) {
            std::cout << "Ошибка: длина линии должна быть целым числом от 1 до 30. Введите --help" << std::endl;
            return 1;
        }
    } catch (std::invalid_argument&) {
        std::cout << "Ошибка: длина линии должна быть целым числом от 1 до 30. Введите --help" << std::endl;
        return 1;
    }

    // Проверка третьего аргумента
    if (std::string(argv[3]) == "Y") {
        epilepsia = true;
    } else if (std::string(argv[3]) == "N") {
        epilepsia = false;
    } else {
        std::cout << "Ошибка: третий аргумент должен быть 'Y' или 'N'. Введите --help" << std::endl;
        return 1;
    }

    AppManager app(epilepsia, line_len, speed);
    app.run();

    return 0;
}
