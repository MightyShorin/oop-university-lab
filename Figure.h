//
// Created by Сергей Шорин on 13.12.2024.
//

#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    virtual void move() = 0;
private:
    virtual void clearLast() = 0;
};

#endif //FIGURE_H
