#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"
#include <iostream>
#include <vector>

class Queue : public List {
private:
    Node* front_;
    Node* rear_;
    size_t size_;

public:
    // Конструктор
    Queue();

    // Конструктор копирования
    Queue(const Queue& other);

    // Оператор присваивания
    Queue& operator=(const Queue& other);

    // Деструктор
    ~Queue();

    // Метод Push (enqueue)
    void Push(int value);

    // Метод Pop (dequeue)
    void Pop();

    // Метод Front
    int& Front() const;

    // Метод Size
    size_t Size() const;

    // Реализация виртуальных методов begin() и end()
    Iterator begin() override;
    Iterator end() override;

    // Реализация виртуальных методов cbegin() и cend()
    ConstIterator cbegin() const override;
    ConstIterator cend() const override;

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Queue& q);

    // Дружественная функция swap
    friend void swap(Queue& first, Queue& second);
};

#endif // QUEUE_HPP
