//
// Created by Сергей Шорин on 20.10.2024.
//

#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "Line.h"
#include <cstdlib>
#include <ctime>
#include <set>

// отсутствует состояние (переменные), а метод статический, который
// не зависит от экзмепляров класса, поэтому деструктор не нужен

class AppManager {
public:
    AppManager(bool epilepsia, size_t line_len, size_t speed, size_t frequency);
    void run();
    void inputParameters();  // Метод для ввода параметров

private:
    bool epilepsia;
    size_t line_len;
    size_t speed;
    size_t frequency;
    size_t term_height, term_width;

    void performAction(size_t time_point, std::unordered_map<size_t, std::vector<Line>>& time_lines);
    bool keyPressed(char &key); // функция проверки ввода
};

#endif //APPMANAGER_H
