//
// Created by abasiy on ۰۴/۱۱/۲۰۲۳.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

template <class T>
class Stack {
private:
    T *array;
    int top = -1;
    int max;
public:
    Stack<T>(int max_size) {
        max = max_size;
        array = new T[max];
    }
    void push(T value) {
        if (!isFull()) {
            array[++top] = value;
        }
    }
    T pop() {
        if (!isEmpty()) {
            return array[top--];
        } else {
            return NULL;
        }
    }

    bool isFull() {
        return (top == max);
    }

    bool isEmpty() {
        return (top == -1);
    }

};

#endif //DATASTRUCTURE_STACK_H
