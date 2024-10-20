//
// Created by Владислав Ковригин on 06.10.2024.
//

#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

using namespace std;

class Console {
public:
    void setCursorPosition(int x, int y) {
        cout << "\033[" << y << ";" << x << "H";
        cout.flush();
    }
    void setTextColor(int x) {
        cout << "\033[0" << ";" << x << "m";
    }
    void setDefault() {
        cout << "\033[0m";
    }
    void getConsoleSize(int &width, int &height) {
        FILE* fp = popen("stty size", "r");
        if (fp == nullptr) {
            std::cerr << "Ошибка при получении размера консоли." << std::endl;
            return;
        }
        fscanf(fp, "%d %d", &height, &width); // Чтение высоты и ширины
        pclose(fp);
    }

};



#endif //CONSOLE_H
