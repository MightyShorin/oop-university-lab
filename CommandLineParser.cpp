//
// Created by Сергей Шорин on 21.10.2024.
//

#include "CommandLineParser.h"

CommandLineParser::CommandLineParser(int argc, char* argv[])
    : argc(argc), argv(argv), speed(0), line_len(0), epilepsia(false) {}

// Используем в MAIN для проверки успеха
int CommandLineParser::parse() {
    if (argc >= 2 && std::string(argv[1]) == "--help") {
        printHelp();
        return 1; // Обработка помощи
    }

    if (argc != 4 && argc != 1) {
        std::cerr << "Ошибка: Ожидается три аргумента. Введите --help" << std::endl;
        return 1;
    }

    // если аргументов нет
    if (argc == 1) {
        speed = 5; // избавиться от  этого перегрузкой конструктора
        line_len = 5;
        epilepsia = true;
        return 2; // Используем значения по умолчанию
    }

    if (parseSpeed() && parseLineLength() && parseEpilepsia()) {
        return 3;
    } else {
        return 1;
    }

}

// Методы для возврата значений в MAIN
size_t CommandLineParser::getSpeed() const {
    return speed;
}
size_t CommandLineParser::getLineLength() const {
    return line_len;
}
bool CommandLineParser::isEpilepsia() const {
    return epilepsia;
}


void CommandLineParser::printHelp() const {
    std::cout << "Использование: программа [скорость] [длина линии] [эпилепсия]\n";
    std::cout << "где:\n";
    std::cout << "  скорость - целое число от 1 до 30\n";
    std::cout << "  длина линии - целое число от 1 до 30\n";
    std::cout << "  эпилепсия - 'Y' (включить режим эпилепсии) или 'N' (выключить)\n";
}

bool CommandLineParser::parseSpeed() {
    try {
        speed = std::stoi(argv[1]);
        if (speed < 1 || speed > 30) {
            std::cerr << "Ошибка: скорость должна быть целым числом от 1 до 30. Введите --help" << std::endl;
            return false;
        }
    } catch (std::invalid_argument&) {
        std::cerr << "Ошибка: скорость должна быть целым числом от 1 до 30. Введите --help" << std::endl;
        return false;
    }
    return true;
}

bool CommandLineParser::parseLineLength() {
    try {
        line_len = std::stoi(argv[2]);
        if (line_len < 1 || line_len > 30) {
            std::cerr << "Ошибка: длина линии должна быть целым числом от 1 до 30. Введите --help" << std::endl;
            return false;
        }
    } catch (std::invalid_argument&) {
        std::cerr << "Ошибка: длина линии должна быть целым числом от 1 до 30. Введите --help" << std::endl;
        return false;
    }
    return true;
}

bool CommandLineParser::parseEpilepsia() {
    std::string arg = argv[3];
    if (arg == "Y") {
        epilepsia = true;
    } else if (arg == "N") {
        epilepsia = false;
    } else {
        std::cerr << "Ошибка: третий аргумент должен быть 'Y' или 'N'. Введите --help" << std::endl;
        return false;
    }
    return true;
}
