#pragma once

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

template<typename T> class MyStack : public stack<T> {

};

template<typename T> void push(MyStack<T>& ms, T value) noexcept {
    ms.push(value);
}

template<typename T> T pop(MyStack<T>& ms) noexcept {
    if (ms.empty()) {
        throw "Empty Stack!!!";
    }
    T value = ms.top();
    ms.pop();
    return value;
}

void my_terminate() noexcept {
    std::cout << "Custom terminate called !!!";
}

int main()
{
    MyStack <int> ms;
    std::set_terminate(my_terminate);

    push(ms, 10);
    push(ms, 20);
    push(ms, 30);
    push(ms, 40);

    cout << pop(ms) << endl;
    cout << pop(ms) << endl;
    cout << pop(ms) << endl;
    cout << pop(ms) << endl;
    cout << pop(ms) << endl;

    return 0;
}