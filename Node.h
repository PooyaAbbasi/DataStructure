//
// Created by abasiy on ۱۷/۱۱/۲۰۲۳.
//

#ifndef UNTITLED3_NODE_H
#define UNTITLED3_NODE_H

template <class T>
class Node{
private:
    T data;
    Node* next;
    Node* pre;
public:
    Node(T data, Node<T> *next = nullptr, Node<T> *before = nullptr) {
        this->data = data;
        this->next = next;
        this->pre = before;
    }

    Node* nextNode() const{
        return this->next;
    }

    void setNextNode(Node<T> *node){
        this->next = node;
    }

    T value() const{
        return this->data;
    }

    Node<T>* preNode() const{
        return this->pre;
    }

    void setPreNode(Node<T> *node){
        this->pre = node;
    }

};

#endif //UNTITLED3_NODE_H
