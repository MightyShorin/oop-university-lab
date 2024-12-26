//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Line.h"
#include "Explosion.h"
#include "ColorManager.h"
#include <thread>
#include <chrono>

Line::Line(size_t length, size_t terminal_height, bool epilepsia)
    : len(length), len_on_screen(0), bool_counter(false), terminal_height(terminal_height),
      color(ColorManager::getRandomColor(epilepsia)) {
    current_coordinates = Point(0, 0); // второй конструктор для дефолта внутри point
}

void Line::setStartXY(size_t x, size_t y) {
    current_coordinates.setX(x);
    current_coordinates.setY(y);
}

size_t Line::getLenOnScreen() const {
    return len_on_screen;
}

void Line::shorten() {
    if (len_on_screen > 0 && !symbols.empty()) {
        symbols.pop_back(); // Удаляем символ из контейнера
        len_on_screen--; // Уменьшаем длину линии
        len--;
    }
}


size_t Line::getCurrentX() const {
    return current_coordinates.getX();
}

size_t Line::getCurrentY() const {
    return current_coordinates.getY();
}

void Line::move() {
    if (current_coordinates.getY() < terminal_height) {
        // Проверка, если не достигли нижней границы терминала
        // Генерируем случайный символ в пределах ASCII диапазона 33-126
        Symbol symbol(color);

        if (bool_counter) {
            current_coordinates.setX(current_coordinates.getX() - 1);
            symbol.draw(current_coordinates.getX(), current_coordinates.getY()); // делаем сдвиг для зиг-зага
            bool_counter = false;
        } else {
            current_coordinates.setX(current_coordinates.getX() + 1);
            symbol.draw(current_coordinates.getX(), current_coordinates.getY());
            bool_counter = true;
        }

        symbols.emplace_back(symbol); // добавим символ с координатами в контейнер

        current_coordinates.setY(current_coordinates.getY() + 1); // Увеличиваем координату y (движение вниз)
        len_on_screen++;


        if (len_on_screen <= len) {
            std::cout.flush();
        }

        if (len_on_screen > len) {
            clearLast();
            std::cout.flush();
        }
    } else {
        clearLast();
        std::cout.flush();
    }
}

// конструктор символа !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Line::clearLast() {
    if (!symbols.empty()) {
        const Symbol &last_symbol = symbols.front(); // получаем самый старый символ по ссылке
        size_t x = last_symbol.getX();
        size_t y = last_symbol.getY();

        std::cout << "\033[" << y << ";" << x << "H "; // очищаем символ на экране
        symbols.erase(symbols.begin()); // освобождаем память
        len_on_screen--;
    }
}

Line::~Line() {
    // пока не нужно
    // current_coordinates — это объект Point, для которого будет вызван собственный деструктор
    // color — это строка, которая сама уничтожится
    // типы (size_t, bool) не требуют явной очистки
}
