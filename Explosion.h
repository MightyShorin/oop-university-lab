//
// Created by Сергей Шорин on 14.12.2024.
//

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Figure.h"
#include <iostream>

class Explosion : public Figure {
public:
    Explosion(size_t x, size_t y, size_t min_radius, size_t max_radius, size_t term_width, size_t term_height);
    bool isComplete() const { return is_complete; }
    void move() override;

private:
    size_t center_x;
    size_t center_y;
    size_t max_radius;
    size_t term_width;
    size_t term_height;

    bool is_complete;
    size_t radius;

    void clearLast() override;
};



#endif //EXPLOSION_H
