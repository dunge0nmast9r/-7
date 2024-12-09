#ifndef LIST_HPP
#define LIST_HPP

#include <iterator>

// Абстрактный базовый класс List
class List {
protected:
    // Внутренний класс Node
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

public:
    virtual ~List() {}

    // Вложенный класс Iterator
    class Iterator {
    protected:
        Node* current;

    public:
        // Конструктор
        Iterator(Node* node) : current(node) {}

        // Перегрузка оператора разыменования
        int& operator*() const { return current->data; }

        // Перегрузка оператора префиксного инкремента
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        // Перегрузка оператора сравнения
        bool operator!=(const Iterator& other) const { return current != other.current; }

        // Доступ к текущему узлу
        Node* getNode() const { return current; }
    };

    // Вложенный класс ConstIterator
    class ConstIterator {
    protected:
        const Node* current;

    public:
        // Конструктор
        ConstIterator(const Node* node) : current(node) {}

        // Перегрузка оператора разыменования
        const int& operator*() const { return current->data; }

        // Перегрузка оператора префиксного инкремента
        ConstIterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        // Перегрузка оператора сравнения
        bool operator!=(const ConstIterator& other) const { return current != other.current; }

        // Доступ к текущему узлу
        const Node* getNode() const { return current; }
    };

    // Чисто виртуальные методы для итераторов
    virtual Iterator begin() = 0;
    virtual Iterator end() = 0;
    virtual ConstIterator cbegin() const = 0;
    virtual ConstIterator cend() const = 0;
};

#endif // LIST_HPP
