//
// Created by Сергей Шорин on 21.10.2024.
//

#include "ColorManager.h"


void ColorManager::setGreenColor() {
    std::cout << "\033[32m";  // Устанавливаем зелёный цвет
}

void ColorManager::setRandomColor() {
    std::cout << "\033[38;5;" << std::rand() % 256 << "m";  // Устанавливаем случайный цвет
}