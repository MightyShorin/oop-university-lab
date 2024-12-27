//
// Created by Сергей Шорин on 27.12.2024.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"

template <typename T>
class ArrayList : public List<T> {
private:
    T* arr;  // указатель на массив
    size_t elemCount;
    size_t maxCapacity;  // вместимость массива

    void expand() {
        maxCapacity *= 2;
        T* newArr = new T[maxCapacity];  // создаём новый массив в два раза больше
        for (size_t i = 0; i < elemCount; ++i) {
            newArr[i] = arr[i];  // перенесем элементы
        }
        delete[] arr;  // удаляем старый массив
        arr = newArr;
    }

public:
    ArrayList() : elemCount(0), maxCapacity(10) {
        arr = new T[maxCapacity];
    }

    ~ArrayList() override {
        delete[] arr;
    }

    void addToEnd(const T& val) override {  // push_back
        if (elemCount == maxCapacity) expand();
        arr[elemCount++] = val;  // обращаемся к элементу по индексу, а потом увеличиваем его
    }

    void addToPosition(size_t index, const T& val) override {  // insert
        if (index > elemCount) throw std::out_of_range("Index out of range");
        if (elemCount == maxCapacity) expand();
        for (size_t i = elemCount; i > index; --i) {  // сдвигаем все элементы вправо с конца до index
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        ++elemCount;
    }

    void removeFromPosition(size_t index) override {  // erase
        if (index >= elemCount) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < elemCount - 1; ++i) {
            arr[i] = arr[i + 1];  // сдвигаем все элементы влево, нужный затёрся
        }
        --elemCount;
    }

    size_t getSize() const override {  // size
        return elemCount;
    }
};


#endif //ARRAYLIST_H
