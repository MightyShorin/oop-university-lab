//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Symbol.h"


Symbol::Symbol(char symbol) : symbol(symbol) {}

void Symbol::draw(size_t x, size_t y) const {
    std::cout << "\033[" << y << ";" << x << "H" << symbol;  // Перемещаем курсор и рисуем символ
}


// Библиотека ncurses