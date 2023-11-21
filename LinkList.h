//
// Created by abasiy on ۱۷/۱۱/۲۰۲۳.
//

#ifndef UNTITLED3_LINKLIST_H
#define UNTITLED3_LINKLIST_H
#include "Node.h"
#include <cstddef>
#include <iostream>

template <class T>
class LinkList{
private:
    Node<T> *list_head;

public:
    LinkList(Node<T> *list_head = nullptr){

        this->list_head = list_head;
    }

    Node<T> *begin(){
        return this->list_head;
    }

    bool isEmpty(){
        return this->list_head == nullptr;
    }

    void pushFront(T value){
        this->list_head = new Node<T>(value, begin());
        Node<T> *next_node = this->begin()->nextNode();
        if (next_node != nullptr) {
            next_node->setPreNode(list_head);
        }
    }

    T popFront(){
        if (isEmpty()) {
            return NULL;
        }
        T value = begin()->value();
        Node<T> *ptr = begin();
        this->list_head = begin()->nextNode();
        begin()->setPreNode(nullptr);
        delete ptr;
        return value;
    }

    T front(){
        if (isEmpty()) {
            return NULL;
        }
        return this->begin()->value();
    }

    Node<T> *end(){
        if (isEmpty()) {
            return nullptr;
        } else {
            Node<T> *ptr = begin();
            while (ptr->nextNode() != nullptr) {
                ptr = ptr->nextNode();
            }
            return ptr;
        }
    }

    T last(){
        return end()->value();
    }

    void pushEnd(T value){
        Node<T> *current_end = this->end();
        this->end()->setNextNode(new Node<T>(value, nullptr, end()));
        // the end is changed now
        if (end() != begin()) {
            this->end()->setPreNode(current_end);
        }
    }

    T popEnd(){
        if (isEmpty()) {
            return NULL;
        }
        Node<T>* end_ptr = end();
        T value = end_ptr->value();
        end()->preNode()->setNextNode(nullptr);
        delete end_ptr;
        return value;
    }

    int length(){
        int len = 0;
        Node<T>* ptr = begin();
        while (ptr != nullptr){
            ptr = ptr->nextNode();
            len ++;
        }
        return len;
    }

    Node<T> *getNodeAt(int index) {
        Node<T> *ptr = begin();
        while (index > 0) {
            ptr = ptr->nextNode();
            if (ptr == nullptr) {
                std::cout << "index is out of bounds! \n";
                return nullptr;
            }
            index--;
        }
        return ptr;
    }



    void insertAt(int index, T value){
        Node<T>* current_node_at_index = getNodeAt(index);
        Node<T>* previous_node = current_node_at_index->preNode();
        Node<T> *node_to_insert = new Node<T>(value, current_node_at_index, previous_node);
        previous_node->setNextNode(node_to_insert);
        current_node_at_index->setPreNode(node_to_insert);

    }

    void eraseNodeAt(int index){
        Node<T> *node = getNodeAt(index);
        if (node == nullptr) {
            return;
        }
        eraseNode(node);
    }

    void eraseNode(const Node<T> *node){
        Node<T> *next_node = node->nextNode();
        Node<T> *pre_node = node->preNode();

        if (next_node != nullptr) {
            next_node->setPreNode(pre_node);
        }

        if (pre_node != nullptr) {
            pre_node->setNextNode(next_node);
        } else {
            this->list_head = node->nextNode();
        }

        delete node;
    }

    int find(T value){
        /**
         * returns the index of element with passed value
         * returns -1 when matched element notfound */
        Node<T>* ptr = begin();
        int index = 0;
        while (ptr != nullptr) {
            if (ptr->value() == value) {
                return index;
            }
            ptr = ptr->nextNode();
            index++;
        }
        return -1;
    }

    int count(T value){
        if (isEmpty()) {
            return -1;
        }
        int counter = 0;
        for (Node<T>* ptr = begin() ; ptr != nullptr ; ptr = ptr->nextNode()) {
            if (ptr->value() == value) {
                counter++;
            }
        }
        return counter;
    }

    void eraseNodesWithValue(T value){
        int count_erases = 0;
        Node<T> *ptr = begin();
        Node<T> *to_delete;
        while (ptr != nullptr){
            to_delete = ptr;
            ptr = ptr->nextNode();
            if (to_delete->value() == value) {

                eraseNode(to_delete);
                count_erases ++;
            }
        }
        if (count_erases == 0) {
            cout << " No match founded " << endl;
        }
    }

    void clear(){
        Node<T>* ptr;
        for (ptr = begin() ; ptr != nullptr ; ptr = ptr->nextNode()) {
            delete ptr->preNode();
        }
        delete ptr;
        list_head = nullptr;
    }

    void print(){
        Node<T>* ptr = this->begin();
        std::cout<< "\n{ ";
        while (ptr != nullptr) {
            std::cout<< ptr->value() << ", ";
            ptr = ptr->nextNode();
        }
        std::cout<< "}\n";

    }

    void printReverse(){
        Node<T>* ptr = this->end();
        std::cout<< "\n{ ";
        while (ptr != nullptr) {
            std::cout<< ptr->value() << ", ";
            ptr = ptr->preNode();
        }
        std::cout<< "}\n";
    }
};

#endif //UNTITLED3_LINKLIST_H
