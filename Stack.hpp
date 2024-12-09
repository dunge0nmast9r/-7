#ifndef STACK_HPP
#define STACK_HPP

#include "List.hpp"
#include <iostream>
#include <vector>

class Stack : public List {
private:
    Node* top_;
    size_t size_;

public:
    // Конструктор
    Stack();

    // Конструктор копирования
    Stack(const Stack& other);

    // Оператор присваивания
    Stack& operator=(const Stack& other);

    // Деструктор
    ~Stack();

    // Метод Push
    void Push(int value);

    // Метод Pop
    void Pop();

    // Метод Top
    int& Top() const;

    // Метод Size
    size_t Size() const;

    // Реализация виртуальных методов begin() и end()
    Iterator begin() override;
    Iterator end() override;

    // Реализация виртуальных методов cbegin() и cend()
    ConstIterator cbegin() const override;
    ConstIterator cend() const override;

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Stack& s);

    // Дружественная функция swap
    friend void swap(Stack& first, Stack& second);
};

#endif // STACK_HPP
