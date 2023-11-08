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

    Queue(int max_size) {
        this->max_size = max_size;
        last = 0;
        front = 0;
        arr = new T[max_size];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return (last + 1) % max_size == front;
    }

    bool isEmpty() {
        return last == front;
    }

    void insert(T value) {
        if (!isFull()) {
            arr[last] = value;
            last = (last + 1) % max_size;
        }
    }

    T delete_() {
        if (!isEmpty()) {
            return arr[front++];
        } else {
            // Handle the error case when the queue is empty
        }
    }
};

#endif //UNTITLED3_QUEUE_H
