//
// Created by Сергей Шорин on 27.12.2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"

template <typename T>
class LinkedList : public List<T> {
private:
    struct Node {
        T val;  // значение узла
        Node* nxt; // указатель на следующий узел
        Node(const T& v) : val(v), nxt(nullptr) {}
    };

    Node* firstElem;  // если список пуст, то =nullptr - указатель на первый узел
    size_t elemCount;

public:
    LinkedList() : firstElem(nullptr), elemCount(0) {}

    ~LinkedList() override {
        while (firstElem) {
            Node* tmp = firstElem;  // временный указатель
            firstElem = firstElem->nxt;
            delete tmp;
        }
    }

    void addToEnd(const T& v) override {
        Node* newNode = new Node(v);
        if (!firstElem) {  // если список пуст firstElem == nullptr
            firstElem = newNode;
        } else {
            Node* cur = firstElem;
            while (cur->nxt) {  // обращение к полю nxt текущего узла, возвращающее указатель на следующий узел (если он существует)
                cur = cur->nxt;
            }
            cur->nxt = newNode;
        }
        ++elemCount;
    }

    void addToPosition(size_t index, const T& v) override {
        if (index > elemCount) throw std::out_of_range("Index out of range");
        Node* newNode = new Node(v);
        if (index == 0) {
            newNode->nxt = firstElem;
            firstElem = newNode;  // сохраняем новый укзатель, чтобы не потерять
        } else {
            Node* cur = firstElem;
            for (size_t i = 0; i < index - 1; ++i) {  // так как индексация с 0
                cur = cur->nxt;
            }
            newNode->nxt = cur->nxt;  // новый теперь указывает на следующий
            cur->nxt = newNode; // текущий теперь указывает на новый
        }
        ++elemCount;
    }

    void removeFromPosition(size_t index) override {
        if (index >= elemCount) throw std::out_of_range("Index out of range");
        Node* cur = firstElem;
        if (index == 0) {
            firstElem = firstElem->nxt;  // переопределяем указатель на первый элемент, ссылаемся на второй
        } else {
            for (size_t i = 0; i < index - 1; ++i) {  // до момента, когда текущий указывает на узел перед удаляемым
                cur = cur->nxt;
            }
            Node* toDelete = cur->nxt;  // сохраним указатель на удаляемый узел
            cur->nxt = toDelete->nxt;  // который перед теперь указывает на тот, который после
            delete toDelete;
        }
        --elemCount;
    }

    size_t getSize() const override {
        return elemCount;
    }

    T& getElementAt(size_t index) {
        if (index >= elemCount) throw std::out_of_range("Index out of range");
        Node* cur = firstElem;
        for (size_t i = 0; i < index; ++i) {
            cur = cur->nxt;
        }
        return cur->val;
    }
};


#endif //LINKEDLIST_H
