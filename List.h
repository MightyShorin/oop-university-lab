//
// Created by Сергей Шорин on 27.12.2024.
//

#ifndef LIST_H
#define LIST_H

#include <cstddef> // Для size_t
#include <stdexcept> // Для std::out_of_range

template <typename T>
class List {
public:
    virtual void addToEnd(const T& value) = 0; // •	Метод добавления элемента в конец
    virtual void addToPosition(size_t index, const T& value) = 0; // •	Метод добавления элемента в позицию n
    virtual void removeFromPosition(size_t index) = 0; // •	Метод удаления элементы из позиции n
    virtual size_t getSize() const = 0; // •	Метод взятия текущего количества элементов
    virtual ~List() = default;
};

#endif //LIST_H
