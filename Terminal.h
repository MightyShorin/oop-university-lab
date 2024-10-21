//
// Created by Сергей Шорин on 21.10.2024.
//

#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <sys/ioctl.h>  // Для получения размера терминала
#include <unistd.h>     // Для использования STDOUT_FILENO

class Terminal {
public:
    static void clearScreen();
    static void getSize(size_t &width, size_t &height);
};



#endif //TERMINAL_H
