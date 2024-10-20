//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Symbol.h"


Symbol::Symbol() {
    symbol = static_cast<char>(std::rand() % 93 + 33);  // Генерация случайного символа
}

void Symbol::draw(size_t x, size_t y) {
    std::cout << "\033[" << y << ";" << x << "H" << symbol;  // Перемещаем курсор и рисуем символ
}