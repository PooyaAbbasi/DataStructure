//
// Created by abasiy on ۰۷/۱۱/۲۰۲۳.
//

#ifndef UNTITLED3_QUEUE_H
#define UNTITLED3_QUEUE_H

template<class T>
class Queue {
private:
    int last;
    int front;
    T *arr;
    int max_size;

public:

    Queue(int max_size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void insert(T value);
    T delete_();

};


#endif //UNTITLED3_QUEUE_H
