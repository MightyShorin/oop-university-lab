//
// Created by Сергей Шорин on 20.10.2024.
//

#include "AppManager.h"
#include "Terminal.h"
#include "InputHandler.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <termios.h> // Для управления терминалом
#include <unistd.h>  // Для STDIN_FILENO
#include <fcntl.h>   // Для fcntl и флагов F_GETFL, F_SETFL, O_NONBLOCK

AppManager::AppManager(bool epilepsia, size_t line_len, size_t speed, size_t frequency)
    : epilepsia(epilepsia), line_len(line_len), speed(speed), frequency(frequency) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // инициализация генератора случайных чисел
}

void AppManager::inputParameters() {
    InputHandler::getParameters(frequency, speed, line_len, epilepsia);
}

void AppManager::run() {
    std::cout << "\033[?25l"; // cкрываем курсор

    Terminal::clearScreen(); // очистка экрана

    Terminal::getSize(term_width, term_height); // получение размеров терминала

    const size_t time_point_min = 0;
    const size_t time_point_max = 1000;
    std::unordered_map<size_t, std::vector<Line> > time_lines; // хранение живых линий по времени
    std::unordered_map<size_t, size_t> counters; // таймеры для каждого времени

    std::set<size_t> unique_keys; // нам нужны уникальные времена

    while (unique_keys.size() < frequency) {
        size_t random_time_point = time_point_min + std::rand() % (time_point_max - time_point_min + 1);
        // формула подходит под любой диапазон
        unique_keys.insert(random_time_point);
    }

    // заполняем unordered_map
    for (const auto &key: unique_keys) {
        time_lines[key] = {}; // пока пустуют, грусть, печаль
        counters[key] = key; // таймеры ставим на максимум
    }

    size_t interval = 1000 / speed; // интервал в миллисекундах

    char exit;
    size_t time = 0;
    while (true) {
        // выход из программы по нажатию клавиши 'q' или 'Q'
        if (keyPressed(exit) && (exit == 'q' || exit == 'Q')) {
            break;
        }

        for (auto &[time_point, lines]: time_lines) {
            if ((time - time_point) % interval == 0) {
                // движение линий из каждого вектора в нужное время (интервал в разное время)
                for (auto it = lines.begin(); it != lines.end();) {
                    it->move();
                    if (it->getLenOnScreen() == 0) {
                        it = lines.erase(it); // удаление и обновление итератора
                    } else {
                        ++it; // переход к следующему элементу
                    }
                }
            }
        }

        // создаем новые линии на основании таймеров
        for (auto &[key, count]: counters) {
            if (count == 0) {
                time_lines[key].emplace_back(line_len, term_height, epilepsia);
                time_lines[key].back().setStartXY(2 + std::rand() % (term_width - 2), 1);

                count = time_point_max; // секунда кончилась, начинаем новую
            }
            count--; // задержка 1 миллисекунда, поэтому уменьшаем на 1
        }

        std::cout << "\033[" << 1 << ";" << 1 << "H";
        // Задержка, чтобы не перегружать CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        time += 1;

        // обнуление времени, чтобы не переполнялось
        if (time == 60000) {
            time = 0;
        }
    }

    std::cout << "\033[?25h"; // возвращаем курсор
}

bool AppManager::keyPressed(char &key) {
    struct termios oldt, newt; // для сохранения старых и установки новых параметров терминала
    int oldf; // для сохранения флагов
    char ch; // для хранения символа с клавиатуры

    tcgetattr(STDIN_FILENO, &oldt); // сохраняем текущие настройки терминала
    newt = oldt; // копия старых настроек
    // отключаем канонический ввод (чтобы считывать без Enter) и вывод символов (чтобы не печатались символы)
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // применяем новые настройки

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // устанавливаем неблокирующий ввод, чтобы не ждать и возвращать 0

    // читаем символ, если он есть
    if (read(STDIN_FILENO, &ch, 1) > 0) {
        key = ch;
        // восстанавливаем настройки терминала
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        return true;
    }

    // восстанавливаем настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    return false;
}
