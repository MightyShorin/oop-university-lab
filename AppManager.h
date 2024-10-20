//
// Created by Сергей Шорин on 20.10.2024.
//

#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "Line.h"
#include <cstdlib>
#include <ctime>
#include <sys/ioctl.h>  // Для получения размера терминала
#include <unistd.h>     // Для использования STDOUT_FILENO


class AppManager {
public:
    AppManager(bool epilepsia, size_t line_len, size_t speed);
    void run();
    void inputParameters();  // Метод для ввода параметров

private:
    bool epilepsia;
    size_t line_len;
    size_t speed;

    void getTerminalSize(size_t &width, size_t &height);

};

#endif //APPMANAGER_H
