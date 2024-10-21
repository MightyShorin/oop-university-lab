//
// Created by Сергей Шорин on 20.10.2024.
//

#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "Line.h"
#include <cstdlib>
#include <ctime>


class AppManager {
public:
    AppManager(bool epilepsia, size_t line_len, size_t speed);
    void run();
    void inputParameters();  // Метод для ввода параметров

private:
    bool epilepsia;
    size_t line_len;
    size_t speed;
};

#endif //APPMANAGER_H
