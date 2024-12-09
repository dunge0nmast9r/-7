#include <iostream>
#include <algorithm>
#include "Stack.hpp"

using namespace std;

// Шаблонный класс numerate
class numerate
{
public:
    numerate(int start = 0, int _shift = 1) : seed(start), shift(_shift) {}
    int operator () () { int old = seed; seed += shift; return old; }
private:
    int seed, shift;
};

// Шаблонная функция sum
int sum(const List& c)
{
    int res = 0;
    for (List::ConstIterator i = c.cbegin(); i != c.cend(); ++i)
        res += *i;
    return res;
}

int main()
{
    // Создаём два стека
    Stack s1, s2;
    numerate f(100);

    // Заполняем первый стек
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    // Заполняем второй стек и копируем s1 в s2
    s2.Push(5);
    s2 = s1;
    s2.Push(4);

    // Выводим s1
    cout << s1 << endl;          // Ожидается: 3->2->1
    cout << s1.Size() << endl;   // Ожидается: 3

    // Выводим s2
    cout << s2 << endl;          // Ожидается: 4->3->2->1
    cout << s2.Size() << endl;   // Ожидается: 4

    // Меняем местами s1 и s2
    swap(s1, s2);

    // Выводим s1 после swap
    cout << s1 << endl;          // Ожидается: 4->3->2->1
    cout << s1.Size() << endl;   // Ожидается: 4

    // Выводим s2 после swap
    cout << s2 << endl;          // Ожидается: 3->2->1
    cout << s2.Size() << endl;   // Ожидается: 3

    // Генерируем новые значения в s1 с помощью numerate
    // Для этого нужно пройтись по итераторам и изменить значения
    for (List::Iterator it = s1.begin(); it != s1.end(); ++it) {
        *it = f();
    }

    // Выводим s1 после генерации
    cout << s1 << endl;          // Ожидается: 100->101->102->103
    cout << s1.Size() << endl;   // Ожидается: 4

    // Вычисляем сумму элементов s2
    cout << sum(s2) << endl;     // Ожидается: 6

    return 0;
}

