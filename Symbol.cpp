//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Symbol.h"


Symbol::Symbol(char symbol, std::string& color) : symbol(symbol), color(color), x(0), y(0) {}

void Symbol::draw(size_t x, size_t y) {
    this->x = x; // Сохраняем координаты
    this->y = y;
    std::cout << "\033[" << y << ";" << x << "H" << color << symbol;  // Перемещаем курсор и рисуем символ
}


// Библиотека ncurses