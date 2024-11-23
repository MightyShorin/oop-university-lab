//
// Created by Сергей Шорин on 21.10.2024.
//

#include "CommandLineParser.h"

CommandLineParser::CommandLineParser(const int argc, char* argv[])
    : argc(argc), argv(argv), frequency(0), speed(0), line_len(0), epilepsia(false) {}

// Используем в MAIN для проверки успеха
int CommandLineParser::parse() {
    if (argc >= 2 && std::string(argv[1]) == "--help") {
        printHelp();
        return 1; // Обработка помощи
    }

    if (argc != 5 && argc != 1) {
        std::cerr << "Ошибка: Ожидается четыре аргумента. Введите --help" << std::endl;
        return 1;
    }

    // если аргументов нет
    if (argc == 1) {
        frequency = 10;
        speed = 5; // избавиться от этого перегрузкой конструктора
        line_len = 5;
        epilepsia = true;
        return 2;
    }

    if (parseFrequency() && parseSpeed() && parseLineLength() && parseEpilepsia()) {
        return 3;
    } else {
        return 1;
    }

}

// Методы для возврата значений в MAIN
size_t CommandLineParser::getFrequency() const {
    return frequency;
}
size_t CommandLineParser::getSpeed() const {
    return speed;
}
size_t CommandLineParser::getLineLength() const {
    return line_len;
}
bool CommandLineParser::isEpilepsia() const {
    return epilepsia;
}


void CommandLineParser::printHelp() {
    std::cout << "Использование: программа [скорость] [длина линии] [эпилепсия]\n";
    std::cout << "где:\n";
    std::cout << "  скорость - целое число от 1 до 30\n";
    std::cout << "  длина линии - целое число от 1 до 30\n";
    std::cout << "  эпилепсия - 'Y' (включить режим эпилепсии) или 'N' (выключить)\n";
}

bool CommandLineParser::parseFrequency() {
    try {
        frequency = std::stoi(argv[1]);
        if (frequency < 1 || frequency > 30) {
            std::cerr << "Ошибка: частота должна быть целым числом от 1 до 30. Введите --help" << std::endl;
            return false;
        }
    } catch (std::invalid_argument&) {
        std::cerr << "Ошибка: частота должна быть целым числом от 1 до 30. Введите --help" << std::endl;
        return false;
    }
    return true;
}

bool CommandLineParser::parseSpeed() {
    try {
        speed = std::stoi(argv[2]);
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
        line_len = std::stoi(argv[3]);
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
    std::string arg = argv[4];
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
