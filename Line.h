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
    Line(size_t length, size_t terminal_height);
    void setStartXY(size_t x, size_t y);
    void setColor(bool epilepsia_mode);
    void draw();

private:
    size_t len;
    Point current_coordinates;
    size_t len_on_screen;
    size_t terminal_height;  // Переменная для хранения высоты терминала
    bool bool_counter;

    void clearLast();
};

#endif //LINE_H
