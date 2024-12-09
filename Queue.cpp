#include "Queue.hpp"

// Конструктор
Queue::Queue() : front_(nullptr), rear_(nullptr), size_(0) {}

// Конструктор копирования
Queue::Queue(const Queue& other) : front_(nullptr), rear_(nullptr), size_(0) {
    if (!other.front_) return;

    // Сохраняем элементы во временный вектор
    std::vector<int> temp;
    Node* current = other.front_;
    while (current) {
        temp.push_back(current->data);
        current = current->next;
    }

    // Добавляем элементы в порядке очереди
    for (auto it = temp.begin(); it != temp.end(); ++it) {
        Push(*it);
    }
}

// Оператор присваивания
Queue& Queue::operator=(const Queue& other) {
    if (this != &other) {
        // Очищаем текущую очередь
        while (front_) {
            Node* temp = front_;
            front_ = front_->next;
            delete temp;
        }
        rear_ = nullptr;
        size_ = 0;

        // Копируем элементы из другой очереди
        if (!other.front_) return *this;

        std::vector<int> temp;
        Node* current = other.front_;
        while (current) {
            temp.push_back(current->data);
            current = current->next;
        }

        for (auto it = temp.begin(); it != temp.end(); ++it) {
            Push(*it);
        }
    }
    return *this;
}

// Деструктор
Queue::~Queue() {
    while (front_) {
        Node* temp = front_;
        front_ = front_->next;
        delete temp;
    }
}

// Метод Push (enqueue)
void Queue::Push(int value) {
    Node* newNode = new Node(value);
    if (!rear_) {
        front_ = rear_ = newNode;
    } else {
        rear_->next = newNode;
        rear_ = newNode;
    }
    size_++;
}

// Метод Pop (dequeue)
void Queue::Pop() {
    if (front_) {
        Node* temp = front_;
        front_ = front_->next;
        if (!front_) rear_ = nullptr;
        delete temp;
        size_--;
    }
}

// Метод Front
int& Queue::Front() const {
    if (front_) return front_->data;
    throw std::out_of_range("Queue is empty");
}

// Метод Size
size_t Queue::Size() const {
    return size_;
}

// Реализация виртуальных методов begin() и end()
List::Iterator Queue::begin() {
    return Iterator(front_);
}

List::Iterator Queue::end() {
    return Iterator(nullptr);
}

// Реализация виртуальных методов cbegin() и cend()
List::ConstIterator Queue::cbegin() const {
    return ConstIterator(front_);
}

List::ConstIterator Queue::cend() const {
    return ConstIterator(nullptr);
}

// Перегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const Queue& q) {
    for (auto it = q.cbegin(); it != q.cend(); ++it) {
        os << *it;
        if (it.getNode()->next != nullptr)
            os << "->";
    }
    return os;
}

// Дружественная функция swap
void swap(Queue& first, Queue& second) {
    using std::swap;
    swap(first.front_, second.front_);
    swap(first.rear_, second.rear_);
    swap(first.size_, second.size_);
}
