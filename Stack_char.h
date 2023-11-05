//
// Created by abasiy on ۰۴/۱۱/۲۰۲۳.
//

#ifndef UNTITLED3_STACK_CHAR_H
#define UNTITLED3_STACK_CHAR_H

class Stack_char {
private:
    char *array;
    int top = -1;
    int max;
public:
    Stack_char(int max_size);
    void push(char value);
    char pop();
    bool isFull();
    bool isEmpty();
};



#endif //UNTITLED3_STACK_CHAR_H
