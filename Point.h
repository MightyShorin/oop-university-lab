//
// Created by Сергей Шорин on 20.10.2024.
//

#ifndef POINT_H
#define POINT_H

#include <cstddef>

class Point {
private:
    size_t x;
    size_t y;

public:
    // Конструктор по умолчанию
    Point(size_t x = 0, size_t y = 0);

    // Геттеры
    size_t getX() const;
    size_t getY() const;

    // Сеттеры
    void setX(size_t x);
    void setY(size_t y);

    // Метод для перемещения точки
    void moveBy(int dx, int dy);
};

#endif //POINT_H
