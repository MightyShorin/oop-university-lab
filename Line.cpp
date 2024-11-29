//
// Created by Сергей Шорин on 20.10.2024.
//

#include "Line.h"
#include "ColorManager.h"
#include <thread>
#include <chrono>

Line::Line(size_t length, size_t terminal_height, bool epilepsia)
    : len(length), offset(len - 1), len_on_screen(0), bool_counter(false), terminal_height(terminal_height), color(ColorManager::getRandomColor(epilepsia)) {
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
            // current_coordinates.setX(current_coordinates.getX() - 1); // Обновляем X перед отрисовкой
            symbol.draw(current_coordinates.getX() - 1, current_coordinates.getY()); // делаем сдвиг для зиг-зага
            // std::cout.flush();
            bool_counter = false;
            // Восстанавливаем X после рисования
            // current_coordinates.setX(current_coordinates.getX() + 1); // Возвращаем X
        } else {
            symbol.draw(current_coordinates.getX(), current_coordinates.getY());
            // std::cout.flush();
            bool_counter = true;
        }

        current_coordinates.setY(current_coordinates.getY() + 1); // Увеличиваем координату y (движение вниз)
        len_on_screen++;

        std::cout.flush();  // методом подгона нашел место для этого метода
        if (len_on_screen == len) {
            clearLast();
        }

    } else {
        std::cout.flush();
        offset--;
        clearLast();
    }
    // std::cout.flush();  // Сброс буфера (так как вывод накапливается и выводится всё разом)
}

void Line::clearLast() {

    // при создании множества змеек в конце терминала сохраняется
    // последнее положение курсора в другом месте терминала
    // и происходит неправильный переход к последнему символу

    std::cout << "\033[s"; // Сохраняем текущее положение курсора
    std::cout << "\033[" << (offset) << "A";  // Перемещаем курсор вверх на len_on_screen строк
    if (offset % 2 == 0) {
        std::cout << "\033[1D";  // Сдвиг влево на 1 символ
    } else if (bool_counter == true) {
        std::cout << "\033[2D";  // Сдвиг влево на 2 символа
    }

    std::cout << " ";  // Заменяем последний символ пробелом

    // if (bool_counter == true) {
    //     std::cout << "\033[1C";
    // }
    // std::cout << "\033[" << (offset) << "B";

    // std::cout << "\033[" << (offset) << "B";  // Возвращаем курсор вниз
    std::cout << "\033[u"; // Восстанавливаем сохраненное положение курсора

    len_on_screen--;

    // std::cout.flush();
}

Line::~Line() {
    // пока не нужно
    // current_coordinates — это объект Point, для которого будет вызван собственный деструктор
    // color — это строка, которая сама уничтожится
    // типы (size_t, bool) не требуют явной очистки
}
