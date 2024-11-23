//
// Created by Сергей Шорин on 21.10.2024.
//

#include "ColorManager.h"


std::string ColorManager::getRandomColor(bool epilepsia) {
    if (epilepsia) {
        std::string color = "\033[38;5;" + std::to_string(std::rand() % 256) + "m";
        return color;
    }
    std::string color = "\033[32m";
    return color;
}
