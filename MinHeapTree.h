//
// Created by abasiy on ۰۷/۱۲/۲۰۲۳.
//

#ifndef DATASTRUCTURE_MINHEAPTREE_H
#define DATASTRUCTURE_MINHEAPTREE_H
#include <iostream>

template<class T>
struct node{
    int priority;
    T data;

    bool operator<(node<T> next) {
        return this->priority < next.priority;
    }

    bool operator<=(node<T> next) {
        return this->priority <= next.priority;
    }

    bool operator>(node<T> next) {
        return this->priority > next.priority;
    }

    bool operator>=(node<T> next) {
        return this->priority >= next.priority;
    }

    bool operator==(node<T> next) {
        return this->priority == next.priority;
    }

    bool operator!=(node<T> next) {
        return this->priority < next.priority;
    }

};


template<class T>
class MinHeapTree {
private:
    node<T> *tree_array;
    int size_of_tree;
    int top;

public:

    MinHeapTree<T>(int max_size){
        size_of_tree = max_size + 1; // +1 because the first cell of tree_array will be left empty;
        this->tree_array = new node<T>[size_of_tree];
        top = 1;
    }

    ~MinHeapTree(){
        delete[] tree_array;
    }

    void insert(T data, int priority){
        if (!this->isFull()) {
            node<T> new_node{priority, data};
            int index_of_new_node = top;
            tree_array[index_of_new_node] = new_node;
            top++;
            int index_of_parent = parent_of(index_of_new_node);

            while (new_node < tree_array[index_of_parent] && index_of_new_node != 1) {
                this->swap(index_of_new_node, index_of_parent);
                index_of_new_node = index_of_parent;
                index_of_parent = parent_of(index_of_new_node);
            }
        } else std::cout << " the Tree has no capacity! ";
    }

    T pop(){
        if (!isEmpty()) {
            T root_data = tree_array[1].data;
            top--;
            tree_array[1] = tree_array[top];
            int index_of_replaced_root = 1;
            int index_of_left_child = indexOfLeftChildOf(index_of_replaced_root);
            int index_of_right_child = indexOfRightChildOf(index_of_replaced_root);
            int index_of_min_child = indexOfMinChild(index_of_left_child, index_of_right_child);

            while (tree_array[index_of_replaced_root] >= tree_array[index_of_min_child]) {

                this->swap(index_of_replaced_root, index_of_min_child);
                index_of_replaced_root = index_of_min_child;
                index_of_left_child = indexOfLeftChildOf(index_of_replaced_root);
                index_of_right_child = indexOfRightChildOf(index_of_replaced_root);

                if (index_of_right_child >= top ) break;
                index_of_min_child = indexOfMinChild(index_of_left_child, index_of_right_child);
            }
            return root_data;
        } else {
            cout << " \n the heap tree is empty! \n";
            return NULL;
        }
    }



    int parent_of(int index){
        return (int)(index / 2);
    }

    int indexOfLeftChildOf(int index){
        return (int)(index * 2);
    }

    int indexOfRightChildOf(int index){
        return (int)(index * 2 + 1);
    }

    int indexOfMinChild(int index_of_left, int index_of_right){
        return (tree_array[index_of_left] > tree_array[index_of_right])? index_of_right: index_of_left;
    }

    void swap(int index1, int index2){
        node<T> buffer = this->tree_array[index1];
        this->tree_array[index1] = tree_array[index2];
        this->tree_array[index2] = buffer;
    }

    bool isFull(){
        return top == size_of_tree;
    }

    bool isEmpty(){
        return top == 1;
    }

    void print(){
        int left_child, right_child;
        for (int i = 1; i < top; ++i) {
            left_child = indexOfLeftChildOf(i);
            right_child = indexOfRightChildOf(i);
            std::cout << " " << tree_array[i].data << "{ ";
            if (left_child < top) std::cout << tree_array[left_child].data << ", ";
            else std::cout << "-, ";
            if (right_child < top) std::cout << tree_array[right_child].data << "} " << endl;
            else std::cout << "-} " << endl;

        }
    }


};

#endif //DATASTRUCTURE_MINHEAPTREE_H
