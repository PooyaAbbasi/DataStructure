//
// Created by abasiy on ۰۴/۱۱/۲۰۲۳.
//


#include "Stack_int.h"

Stack_int::Stack_int(int max_size) {
    max = max_size;
    array = new int[max];
}

void Stack_int::push(int value) {
    if (!isFull()) {
        array[++top] = value;
    }
}

int Stack_int::pop() {
    if (!isEmpty()) {
        return array[top--];
    } else {
        return '\0';
    }
}

bool Stack_int::isFull() {
    return (top == max);
}

bool Stack_int::isEmpty() {
    return (top == -1);
}
