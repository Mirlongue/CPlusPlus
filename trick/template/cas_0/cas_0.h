#ifndef CAS_0_H
#define CAS_0_H

#include <iostream>
namespace cas {

template <typename T> void Swap(T &a, T &b);

template <class T>
class stack;

template <class T>
void Tset(stack<T> &);
template <class T>
class stack {
    friend void Tset<T>(stack<T> &);
    // friend void set<>(stack &); // simplify
public:
    stack() {std::cout << "stack" << std::endl;}
};

}

#endif // CAS_0_H