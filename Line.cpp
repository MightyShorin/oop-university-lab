//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Line.h"
#include "ColorManager.h"
#include <thread>
#include <chrono>

Line::Line(size_t length, size_t terminal_height, bool epilepsia)
    : len(length), len_on_screen(0), bool_counter(false), terminal_height(terminal_height), color(ColorManager::getRandomColor(epilepsia)) {
    current_coordinates = Point(0, 0); // второй конструктор для дефолта внутри point
}

void Line::setStartXY(size_t x, size_t y) {
    current_coordinates.setX(x);
    current_coordinates.setY(y);
}

size_t Line::getLenOnScreen() const {
    return len_on_screen;
}

void Line::move() {

    if (current_coordinates.getY() < terminal_height) { // Проверка, если не достигли нижней границы терминала
        // Генерируем случайный символ в пределах ASCII диапазона 33-126
        char randomSymbol = static_cast<char>(std::rand() % 93 + 33);
        Symbol symbol(randomSymbol, color);

        if (bool_counter) {
            symbol.draw(current_coordinates.getX() - 1, current_coordinates.getY()); // делаем сдвиг для зиг-зага
            bool_counter = false;
        } else {
            symbol.draw(current_coordinates.getX(), current_coordinates.getY());
            bool_counter = true;
        }

        symbols.emplace_back(symbol); // добавим символ с координатами в контейнер

        current_coordinates.setY(current_coordinates.getY() + 1); // Увеличиваем координату y (движение вниз)
        len_on_screen++;

        std::cout.flush();  // методом подгона нашел место для этого метода
        if (len_on_screen == len) {
            clearLast();
        }

    } else {
        std::cout.flush();
        clearLast();
    }
    // std::cout.flush();  // Сброс буфера (так как вывод накапливается и выводится всё разом)
}

void Line::clearLast() {

    if (!symbols.empty()) {
        const Symbol& oldestSymbol = symbols.front(); // получаем самый старый символ по ссылке
        size_t x = oldestSymbol.getX();
        size_t y = oldestSymbol.getY();

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
