//
// Created by Сергей Шорин on 21.10.2024.
//

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H



#include <iostream>
#include <limits>

class InputHandler {
public:
    static void getParameters(size_t &frequency, size_t &speed, size_t &line_len, bool &epilepsia, size_t &chance, size_t &min_radius, size_t &max_radius);
};



#endif //INPUTHANDLER_H
