//
// Created by Сергей Шорин on 20.10.2024.
//

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Symbol {
public:
    Symbol(char symbol, std::string& color);
    void draw(size_t x, size_t y) const;
private:
    char symbol;
    std::string color;
};

#endif //SYMBOL_H
