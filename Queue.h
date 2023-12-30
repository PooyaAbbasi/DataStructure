#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

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
        last = front = 0;
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
        } else {
            cout << " \n the queue is full ! '" << value << "' didn't inserted! \n";
        }
    }

    T delete_() {
        if (!isEmpty()) {
            T x = arr[front];
            front = (front+1) % max_size;
            return x;
        } else {
            cout << "queue is empty ! \n";
            return NULL;
        }
    }
};

#endif //DATASTRUCTURE_QUEUE_H
