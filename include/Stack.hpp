#ifndef STACK_HPP
#define STACK_HPP
#include "StackDugum.hpp"

class Stack {
private:
    StackDugum* tepe;
    int boyut;

public:
    Stack();
    ~Stack();

    void push(int deger);
    int pop();
    bool isEmpty() const;
    int peek() const;
};

#endif
