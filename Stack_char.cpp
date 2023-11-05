//
// Created by abasiy on ۰۴/۱۱/۲۰۲۳.
//

#include "Stack_char.h"

Stack_char::Stack_char(int max_size) {
    max = max_size;
    array = new char[max];
}

void Stack_char::push(char value) {
    if (!isFull()) {
        array[++top] = value;
    }
}

char Stack_char::pop() {
    if (!isEmpty()) {
        return array[top--];
    } else {
        return '\0';
    }
}

bool Stack_char::isFull() {
    return (top == max);
}

bool Stack_char::isEmpty() {
    return (top == -1);
}

