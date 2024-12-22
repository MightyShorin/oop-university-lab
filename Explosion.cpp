//
// Created by Сергей Шорин on 14.12.2024.
//
#include "Explosion.h"
#include "ColorManager.h"
#include <iostream>
#include <cmath> // Для работы с углами и синусами/косинусами

#include "Symbol.h"

Explosion::Explosion(size_t x, size_t y, size_t min_radius, size_t max_radius, size_t term_width, size_t term_height)
    : center_x(x), center_y(y), max_radius(min_radius + std::rand() % (max_radius - min_radius + 1)), is_complete(false), radius(0), term_width(term_width), term_height(term_height) {}

void Explosion::move() {
   if (is_complete) return;

    radius++;

    std::string color = ColorManager::getRandomColor(true); // Получаем случайный цвет

    // отрисовываем новую фазу взрыва
    for (int angle = 0; angle < 360; angle += 15) { // шаг угла для точек круга
        const int dx = static_cast<int>(std::round(radius * std::cos(angle * M_PI / 180.0)));
        const int dy = static_cast<int>(std::round(radius * std::sin(angle * M_PI / 180.0)));
        size_t draw_x = center_x + dx;
        size_t draw_y = center_y + dy;

        // Проверяем границы терминала
        if (draw_x > 0 && draw_x <= term_width && draw_y > 0 && draw_y < term_height) {
            Symbol symbol(color);
            symbol.draw(draw_x, draw_y);
        }
    }

    // if (radius > 1) {
    //     clearLast(); // Очищаем предыдущую фазу
    // }

    std::cout.flush();

    // Проверяем, завершён ли взрыв
    if (radius >= max_radius) {
        is_complete = true;
    }
}


void Explosion::clearLast() {
    // Очистка предыдущей фазы (по аналогии с draw)
    for (int angle = 0; angle < 360; angle += 15) {
        const int dx = static_cast<int>(std::round(radius * std::cos(angle * M_PI / 180.0)));
        const int dy = static_cast<int>(std::round(radius * std::sin(angle * M_PI / 180.0)));
        size_t draw_x = center_x + dx;
        size_t draw_y = center_y + dy;

        if (draw_x > 0 && draw_x <= term_width && draw_y > 0 && draw_y < term_height) {
            std::cout << "\033[" << draw_y << ";" << draw_x << "H "; // Очищаем символ
        }
    }
}