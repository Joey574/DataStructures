#include <iostream>

#include "Stack.h"
#include "Stack.cpp"

int main()
{
    Stack<int> a;

    std::cout << "Start size: " << a.size() << "\n";

    a.push(5);
    a.push(10);

    std::cout << "Top value (peek): " << a.peek() << "\n";
    std::cout << "Popped value: " << a.pop() << "\n";
    std::cout << "Popped value: " << a.pop() << "\n";
    std::cout << "End size: " << a.size() << "\n";

    a.push(0);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);

    std::cout << "Again: " << a.size() << "\n";

    while (a.size() > 0) {
        std::cout << a.pop() << "\n";
    }
}