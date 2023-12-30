//
// Created by abasiy on ۱۰/۱۲/۲۰۲۳.
//

#ifndef DATASTRUCTURE_BINARYSEARCHNODE_H
#define DATASTRUCTURE_BINARYSEARCHNODE_H
#include "iostream"
using namespace std;

template <class T>
class BinarySearchNode{
private:
    BinarySearchNode<T> *left;
    BinarySearchNode<T> *right;
    BinarySearchNode<T> *parent;
    bool isLeftChild;
    bool isRightChild;
public:
    T data;

    BinarySearchNode(T data, BinarySearchNode<T> *parent = nullptr,
                     BinarySearchNode<T> *left = nullptr, BinarySearchNode<T> *right = nullptr){
        this->data = data;
        this->parent = parent;
        this->left = left;
        this->right = right;
        this->isLeftChild = false;
        this->isRightChild = false;
    }

    void setIsLeftChild(bool isLeftChild) {
        this->isLeftChild = isLeftChild;
    }

    void setIsRightChild(bool isRightChild) {
        this->isRightChild = isRightChild;
    }

    ~BinarySearchNode(){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    bool isLeaf(){
        return ( !isLeftChild && !isRightChild);
    }

    bool hasLeftChild(){
        return (isLeftChild);
    }

    bool hasRightChild(){
        return (isRightChild);
    }

    bool hasSingleChild(){
        return (this->hasRightChild() ^ this->hasLeftChild());
    }

    bool hasChild(){
        return (hasLeftChild() || hasRightChild());
    }

    void setLeftChild(T data){
        this->isLeftChild = true;
        this->left = new BinarySearchNode<T>(data, this);
    }

    void setLeftChild(BinarySearchNode<T> *node){
        this->left = node;
    }

    void setRightChild(T data){
        this->isRightChild = true;
        this->right = new BinarySearchNode<T>(data, this);
    }

    void setRightChild(BinarySearchNode<T> *node){
        this->right = node;
    }

    BinarySearchNode *getLeftChild() const{
        return this->left;
    }

    BinarySearchNode *getRightChild() const{
        return this->right;
    }

    void setRightThread(BinarySearchNode<T> *thread_ptr){
        this->right = thread_ptr;
        this->isRightChild = false;
    }

    void setLeftThread(BinarySearchNode<T> *thread_ptr){
        this->left = thread_ptr;
        this->isLeftChild = false;
    }

    BinarySearchNode *getRightThread(){
        return (!hasRightChild() ? this->right : nullptr);
    }

    BinarySearchNode *getLeftThread(){
        return (!hasLeftChild() ? this->left : nullptr);
    }

    void setParent(BinarySearchNode<T> *parent_node){
        this->parent = parent_node;
    }

    BinarySearchNode<T> *getParent(){
        return this->parent;
    }



};

#endif //DATASTRUCTURE_BINARYSEARCHNODE_H
