//
// Created by abasiy on ۰۴/۱۱/۲۰۲۳.
//

#ifndef UNTITLED3_STACK_INT_H
#define UNTITLED3_STACK_INT_H


class Stack_int {
private:
    int *array;
    int top = -1;
    int max;
public:
    Stack_int(int max_size);
    void push(int value);
    int pop();
    bool isFull();
    bool isEmpty();
};



#endif //UNTITLED3_STACK_INT_H
