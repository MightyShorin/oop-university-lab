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

    if (argc != 8 && argc != 1) {
        std::cerr << "Ошибка: Ожидается четыре аргумента. Введите --help" << std::endl;
        return 1;
    }

    // если аргументов нет
    if (argc == 1) {
        frequency = 10;
        speed = 5; // избавиться от этого перегрузкой конструктора
        line_len = 5;
        epilepsia = true;
        chance = 100;
        min_radius = 1;
        max_radius = 7;
        return 2;
    }

    if (parseFrequency() && parseSpeed() && parseLineLength() && parseEpilepsia() && parseChance() && parseMinRadius() && parseMaxRadius()) {
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
size_t CommandLineParser::getChance() const {
    return chance;
}
size_t CommandLineParser::getMinRadius() const {
    return min_radius;
}
size_t CommandLineParser::getMaxRadius() const {
    return max_radius;
}


void CommandLineParser::printHelp() {
    std::cout << "Использование: программа [частота] [скорость] [длина линии] [эпилепсия]\n";
    std::cout << "где:\n";
    std::cout << "  частота - целое число от 1 до 30\n";
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

bool CommandLineParser::parseChance() {
    try {
        chance = std::stoi(argv[5]);
        if (chance < 1 || chance > 1000) {
            std::cerr << "Ошибка: вероятность взрыва должна быть целым числом от 1 до 1000. Введите --help" << std::endl;
            return false;
        }
    } catch (std::invalid_argument&) {
        std::cerr << "Ошибка: вероятность взрыва должна быть целым числом от 1 до 1000. Введите --help" << std::endl;
        return false;
    }
    return true;
}

bool CommandLineParser::parseMinRadius() {
    try {
        min_radius = std::stoi(argv[6]);
        if (min_radius < 1 || min_radius > 10) {
            std::cerr << "Ошибка: минимальный радиус взрыва должен быть целым числом от 1 до 10. Введите --help" << std::endl;
            return false;
        }
    } catch (std::invalid_argument&) {
        std::cerr << "Ошибка: минимальный радиус взрыва должен быть целым числом от 1 до 10. Введите --help" << std::endl;
        return false;
    }
    return true;
}

bool CommandLineParser::parseMaxRadius() {
    try {
        max_radius = std::stoi(argv[7]);
        if (max_radius < 1 || max_radius > 10) {
            std::cerr << "Ошибка: максимальный радиус взрыва должен быть целым числом от 1 до 10. Введите --help" << std::endl;
            return false;
        }
        if (max_radius <= min_radius) {
            std::cerr << "Ошибка: максимальный радиус должен быть больше минимального радиуса." << std::endl;
            return false;
        }
    } catch (std::invalid_argument&) {
        std::cerr << "Ошибка: максимальный радиус взрыва должен быть целым числом от 1 до 10. Введите --help" << std::endl;
        return false;
    }
    return true;
}