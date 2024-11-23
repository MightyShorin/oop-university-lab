//
// Created by Сергей Шорин on 20.10.2024.
//

#ifndef LINE_H
#define LINE_H

#include "Symbol.h"
#include "Point.h"
#include <iostream>


class Line {
public:
    Line(size_t length, size_t terminal_height, bool epilepsia);
    void setStartXY(size_t x, size_t y);
    void move();

private:
    Point current_coordinates;
    size_t len;
    size_t len_on_screen;
    size_t terminal_height;  // Переменная для хранения высоты терминала
    bool bool_counter;
    std::string color; // генерируется в конструкторе

    void clearLast();
};

#endif //LINE_H
