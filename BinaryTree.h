//
// Created by abasiy on ۲۶/۱۱/۲۰۲۳.
//

#ifndef UNTITLED3_BINARYTREE_H
#define UNTITLED3_BINARYTREE_H
#include "BinaryNode.h"

template <class T>
class BinaryTree {
private:

public:

    BinaryNode<T> *root;

    BinaryTree<T>(T root_data){
        this->root = new BinaryNode<T>(root_data);
    }

    BinaryTree<T>(){
        this->root = nullptr;
    }

    int getHeightRecursive(BinaryNode<T> *node){
        if (!node->hasChild()) {
            return 0;
        } else {
            int height_left_child = 0;
            if (node->getLeftChild() != nullptr) {
                height_left_child = getHeightRecursive(node->getLeftChild());
            }
            int height_right_child = 0;
            if (node->getRightChild() != nullptr) {
                height_right_child = getHeightRecursive(node->getRightChild());
            }

            return 1 + ((height_left_child > height_right_child)? height_left_child : height_right_child);
        }
    }

    int height(){
        return getHeightRecursive(this->root);
    }

    int getSizeRecursive(BinaryNode<T> *node){
        if (node->isLeaf()) {
            return 1;
        } else if (node->getLeftChild() == nullptr) {
            return 1 + getSizeRecursive(node->getRightChild());
        } else {
            if (node->getRightChild() != nullptr) {
                return 1 + getSizeRecursive(node->getRightChild()) + getSizeRecursive(node->getLeftChild());
            } else {
                return 1 + getSizeRecursive(node->getLeftChild());
            }
        }
    }

    int size(){
        return getSizeRecursive(this->root);
    }

    void printRecursive(BinaryNode<T> *node){
        if (node == nullptr) return;
        if (node->isLeaf()) {
            return;
        } else {
            cout << node->data << ":";
            if (node->getLeftChild() == nullptr) {
                cout << "left= " << "--" << "  ";
            } else {
                cout << "left= " << node->getLeftChild()->data << "  ";
            }
            if (node->getRightChild() == nullptr) {
                cout << "right= " << "--" << "  ";
            } else {
                cout << "right= " << node->getRightChild()->data << "  ";
            }
            cout << endl;
            printRecursive(node->getLeftChild());
            printRecursive(node->getRightChild());
            return;
        }
    }

    void print(){
        printRecursive(this->root);
    }

};

#endif //UNTITLED3_BINARYTREE_H
