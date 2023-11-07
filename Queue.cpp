//
// Created by abasiy on ۰۷/۱۱/۲۰۲۳.
//

#include "Queue.h"

template<class T>
Queue<T>::Queue(int max_size) {
    max_size = max_size;
    last = 0;
    front = 0;
    arr = new T[max_size];
}

template<class T>
Queue<T>::~Queue() {
    delete[] arr;
}

template<class T>
bool Queue<T>::isFull() {
    return (last + 1) % max_size == front;
}

template<class T>
bool Queue<T>::isEmpty(){
    return last == front;
}


template<class T>
void Queue<T>::insert(T value){
    arr[last] = value;
    last = (last + 1) % max_size;
}

template<class T>
T Queue<T>::delete_(){
    return arr[front++];
}

