//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Line.h"
#include "ColorManager.h"
#include <thread>
#include <chrono>

Line::Line(size_t length, size_t terminal_height)
    : len(length), len_on_screen(0), bool_counter(false), terminal_height(terminal_height) {
    current_coordinates = Point(0, 0);
}

void Line::setStartXY(size_t x, size_t y) {
    current_coordinates.setX(x);
    current_coordinates.setY(y);
}

void Line::setColor(bool epilepsia_mode) {
    if (epilepsia_mode) {
        ColorManager::setRandomColor();  // Устанавливаем случайный цвет для эпилепсии
    } else {
        ColorManager::setGreenColor();  // Устанавливаем зелёный цвет
    }
}

void Line::draw() {
    if (current_coordinates.getY() < terminal_height) { // Проверка, если не достигли нижней границы терминала
        // Генерируем случайный символ в пределах ASCII диапазона 33-126
        char randomSymbol = static_cast<char>(std::rand() % 93 + 33);
        Symbol symbol(randomSymbol);

        if (bool_counter) {
            symbol.draw(current_coordinates.getX() - 1, current_coordinates.getY()); // делаем сдвиг для зиг-зага
            bool_counter = false;
        } else {
            symbol.draw(current_coordinates.getX(), current_coordinates.getY());
            bool_counter = true;
        }

        current_coordinates.setY(current_coordinates.getY() + 1); // Увеличиваем координату y (движение вниз)
        len_on_screen++;

        if (len_on_screen == len) {
            clearLast();
        }

    } else {
        clearLast();
    }
    std::cout.flush();  // Сброс буфера (так как вывод накапливается и выводится всё разом)
}

void Line::clearLast() {
    std::cout << "\033[" << len_on_screen << "A"   // Перемещаем курсор вверх на len_on_screen строк
              << "\033[1G"                         // Перемещаем курсор в начало строки (влево)
              << "\033[K"                          // Очищаем строку от начала до конца
              << "\033[" << len_on_screen << "B";  // Перемещаем курсор обратно вниз (для следующей итерации спуска)
    len_on_screen--;
}
