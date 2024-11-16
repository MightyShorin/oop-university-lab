//
// Created by Сергей Шорин on 21.10.2024.
//

#include "Point.h"

Point::Point(size_t x, size_t y) : x(x), y(y) {}

size_t Point::getX() const {
    return x;
}

size_t Point::getY() const {
    return y;
}

void Point::setX(size_t x) {
    this->x = x;
}

void Point::setY(size_t y) {
    this->y = y;
}
