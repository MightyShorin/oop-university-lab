//
// Created by Сергей Шорин on 20.10.2024.
//

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

class Symbol {
public:
    Symbol(std::string& color);
    void draw(size_t x, size_t y);
    size_t getX() const { return x; }
    size_t getY() const { return y; }

private:
    char symbol;
    std::string color;
    size_t x, y;
};

#endif //SYMBOL_H
