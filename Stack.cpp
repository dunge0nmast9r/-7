#include "Stack.hpp"

// Конструктор
Stack::Stack() : top_(nullptr), size_(0) {}

// Конструктор копирования
Stack::Stack(const Stack& other) : top_(nullptr), size_(0) {
    if (!other.top_) return;

    // Сохраняем элементы во временный вектор
    std::vector<int> temp;
    Node* current = other.top_;
    while (current) {
        temp.push_back(current->data);
        current = current->next;
    }

    // Добавляем элементы в обратном порядке для сохранения порядка в стеке
    for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
        Push(*it);
    }
}

// Оператор присваивания
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        // Очищаем текущий стек
        while (top_) {
            Node* temp = top_;
            top_ = top_->next;
            delete temp;
        }
        size_ = 0;

        // Копируем элементы из другого стека
        if (!other.top_) return *this;

        std::vector<int> temp;
        Node* current = other.top_;
        while (current) {
            temp.push_back(current->data);
            current = current->next;
        }

        for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
            Push(*it);
        }
    }
    return *this;
}

// Деструктор
Stack::~Stack() {
    while (top_) {
        Node* temp = top_;
        top_ = top_->next;
        delete temp;
    }
}

// Метод Push
void Stack::Push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top_;
    top_ = newNode;
    size_++;
}

// Метод Pop
void Stack::Pop() {
    if (top_) {
        Node* temp = top_;
        top_ = top_->next;
        delete temp;
        size_--;
    }
}

// Метод Top
int& Stack::Top() const {
    if (top_) return top_->data;
    throw std::out_of_range("Stack is empty");
}

// Метод Size
size_t Stack::Size() const {
    return size_;
}

// Реализация виртуальных методов begin() и end()
List::Iterator Stack::begin() {
    return Iterator(top_);
}

List::Iterator Stack::end() {
    return Iterator(nullptr);
}

// Реализация виртуальных методов cbegin() и cend()
List::ConstIterator Stack::cbegin() const {
    return ConstIterator(top_);
}

List::ConstIterator Stack::cend() const {
    return ConstIterator(nullptr);
}

// Перегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const Stack& s) {
    for (auto it = s.cbegin(); it != s.cend(); ++it) {
        os << *it;
        if (it.getNode()->next != nullptr)
            os << "->";
    }
    return os;
}

// Дружественная функция swap
void swap(Stack& first, Stack& second) {
    using std::swap;
    swap(first.top_, second.top_);
    swap(first.size_, second.size_);
}
