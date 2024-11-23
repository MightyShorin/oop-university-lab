//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Symbol.h"


Symbol::Symbol(char symbol, std::string& color) : symbol(symbol), color(color) {}

void Symbol::draw(size_t x, size_t y) const {
    std::cout << "\033[" << y << ";" << x << "H" << color << symbol;  // Перемещаем курсор и рисуем символ
}


// Библиотека ncurses