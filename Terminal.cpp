//
// Created by Сергей Шорин on 21.10.2024.
//

#include "Terminal.h"

void Terminal::clearScreen() {
    std::cout << "\033[2J";  // Очистка экрана
}

void Terminal::getSize(size_t &width, size_t &height) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col;   // Ширина терминала
    height = w.ws_row;  // Высота терминала
}

