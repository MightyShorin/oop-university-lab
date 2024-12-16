//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Symbol.h"


Symbol::Symbol(std::string& color) : color(color), x(0), y(0), symbol(static_cast<char>(std::rand() % 93 + 33)) {}

void Symbol::draw(size_t x, size_t y) {
    this->x = x; // Сохраняем координаты
    this->y = y;
    std::cout << "\033[" << y << ";" << x << "H" << color << symbol;  // Перемещаем курсор и рисуем символ
}


// Библиотека ncurses