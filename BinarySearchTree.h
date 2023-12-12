//
// Created by abasiy on ۱۰/۱۲/۲۰۲۳.
//

#ifndef UNTITLED3_BINARYSEARCHTREE_H
#define UNTITLED3_BINARYSEARCHTREE_H

#include "BinaryTree.h"
#include "BinarySearchNode.h"

template<class T>
class BinarySearchTree {
private:
    BinarySearchNode<T> *root;

public:

    BinarySearchTree(T root_data) {
        this->root = new BinarySearchNode<T>(root_data);
    }

    BinarySearchTree() {
        this->root = nullptr;
    }

    int getHeightRecursive(BinarySearchNode<T> *node) {
        if (node->isLeaf()) {
            return 0;
        } else {
            int height_left_child = 0;
            if (node->hasLeftChild()) {
                height_left_child = getHeightRecursive(node->getLeftChild());
            }

            int height_right_child = 0;
            if (node->hasRightChild()) {
                height_right_child = getHeightRecursive(node->getRightChild());
            }

            return 1 + ((height_left_child > height_right_child) ? height_left_child : height_right_child);
        }
    }

    int height() {
        return getHeightRecursive(this->root);
    }

    int getSizeRecursive(BinarySearchNode<T> *node) {
        if (node->isLeaf()) {
            return 1;
        } else if (!node->hasLeftChild()) {
            return 1 + getSizeRecursive(node->getRightChild());
        } else {
            if (node->hasRightChild()) {
                return 1 + getSizeRecursive(node->getRightChild()) + getSizeRecursive(node->getLeftChild());
            } else {
                return 1 + getSizeRecursive(node->getLeftChild());
            }
        }
    }

    int size() {
        return getSizeRecursive(this->root);
    }

    T *LVR() {
        T *lvr = new T[this->size()];
        T *pointer_of_lvr = lvr;
        getLVRrecursive(this->root, pointer_of_lvr);
        return lvr;
    }

    void getLVRrecursive(BinarySearchNode<T> *node, T *&lvr) {

        if (node->hasLeftChild()) {
            getLVRrecursive(node->getLeftChild(), lvr);
        }

        cout << node->data << "-";
        *lvr = node->data;
        lvr++;

        if (node->hasRightChild()) {
            getLVRrecursive(node->getRightChild(), lvr);
        }
    }

    void print() {
        printRecursive(this->root);
    }

    void printRecursive(BinarySearchNode<T> *node) {
        if (node == nullptr) return;
        if (node->isLeaf()) {
            cout << node->data << ":";
            if (node->getLeftChild() != nullptr) cout << " left thread = " << node->getLeftChild()->data << "  ";
            else cout << " left = -- ,";
            if (node->getRightChild() != nullptr) cout << " right thread = " << node->getRightChild()->data << "  ";
            cout << " right = -- \n";
            return;
        } else {
            cout << node->data << ":";
            if (!node->hasLeftChild()) {
                if (node->getLeftChild() != nullptr) cout << " left thread = " << node->getLeftChild()->data << "  ";
                else cout << " left = -- ";
            } else {
                cout << " left= " << node->getLeftChild()->data << "  ";
            }
            if (!node->hasRightChild()) {
                if (node->getRightChild() != nullptr) cout << " right thread = " << node->getRightChild()->data << "  ";
                cout << " right = -- ";
            } else {
                cout << "right= " << node->getRightChild()->data << "  ";
            }
            cout << endl;
            if (node->hasLeftChild()) printRecursive(node->getLeftChild());
            if (node->hasRightChild()) printRecursive(node->getRightChild());
            return;
        }
    }

    void insert(T data) {
        if (this->root == nullptr) {
            this->root = new BinarySearchNode<T>(data);
        } else {
            this->insertRecursive(data, this->root);
        }
    }

    void insertRecursive(T data, BinarySearchNode<T> *root) {
        if (data < root->data) {
            if (root->hasLeftChild()) {
                insertRecursive(data, root->getLeftChild());
            } else {
                root->setLeftChild(data);
                this->setRightThread(root->getLeftChild());
                this->setLeftThread(root->getLeftChild());
            }
        } else if (data > root->data){
            if (root->hasRightChild()) {
                insertRecursive(data, root->getRightChild());
            } else {
                root->setRightChild(data);
                this->setRightThread(root->getRightChild());
                this->setLeftThread(root->getRightChild());
            }
        }
    }

    T front(){
        return frontOf(this->root)->data;
    }

    BinarySearchNode<T> *frontOf(BinarySearchNode<T> *node) {
        while (node->hasLeftChild()) {
            node = node->getLeftChild();
        }
        return node;
    }

    T back(){
        return this->backOf(this->root)->data;
    }

    BinarySearchNode<T> *backOf(BinarySearchNode<T> *node) {
        while (node->hasRightChild()) {
            node = node->getRightChild();
        }
        return node;
    }

    void setRightThread(BinarySearchNode<T> *node) {
        if (!node->hasRightChild()){
            BinarySearchNode<T> *right_thread = nullptr;
            node->setRightThread(findRightThread(node->data, this->root, right_thread));
        }
    }

    BinarySearchNode<T> *findRightThread(T target_data,
                                         BinarySearchNode<T> *root_node,
                                         BinarySearchNode<T> *&right_thread) {
        if (target_data == root_node->data) {
            return right_thread;
        } else if (target_data > root_node->data) {
            return findRightThread(target_data, root_node->getRightChild(), right_thread);
        } else {
            right_thread = root_node;
            return findRightThread(target_data, root_node->getLeftChild(), right_thread);
        }
    }

    void setLeftThread(BinarySearchNode<T> *node) {
        if (!node->hasLeftChild()) {
            BinarySearchNode<T> *left_thread = nullptr;
            node->setLeftThread(this->findLeftThread(node->data, this->root, left_thread));
        }
    }

    BinarySearchNode<T> *findLeftThread(T target_data,
                                        BinarySearchNode<T> *root_node,
                                        BinarySearchNode<T> *&left_thread) {
        if (target_data == root_node->data) {
            return left_thread;
        } else if (target_data > root_node->data) {
            left_thread = root_node;
            return findLeftThread(target_data, root_node->getRightChild(), left_thread);
        } else {
            return findLeftThread(target_data, root_node->getLeftChild(), left_thread);
        }
    }

    BinarySearchNode<T> *findNode(T data, BinarySearchNode<T> *root_node) {
        if (data == root_node->data) {
            return root_node;
        } else if (data < root_node->data) {
            if (root_node->hasLeftChild()) return findNode(data, root_node->getLeftChild());
            else return nullptr;
        } else {
            if (root_node->hasRightChild()) return findNode(data, root_node->getRightChild());
            else return nullptr;
        }
    }

    bool find(T data) {
        return (findNode(data, this->root) != nullptr);
    }

    void erase(T data) {
        BinarySearchNode<T> *node_to_delete = this->findNode(data, this->root);

        if (node_to_delete == nullptr) {
            cout << " this node doesn't exist in the tree.";
            return;

        } else if (node_to_delete->isLeaf()) { // leaf node
            BinarySearchNode<T> *parent = node_to_delete->getParent();
            if (parent->getRightChild() == node_to_delete) {
                parent->setIsRightChild(false);
            } else {
                parent->setIsLeftChild(false);
            }
            delete node_to_delete;
            this->setLeftThread(parent);

        } else if (node_to_delete->hasSingleChild()) { // single child
            *node_to_delete = *((node_to_delete->hasLeftChild()) ?
                             node_to_delete->getLeftChild() :
                             node_to_delete->getRightChild());

        } else { // full node
            BinarySearchNode<T> *back_of_left = this->backOf(node_to_delete->getLeftChild());
            T data_of_backLeft = back_of_left->data;
            erase(back_of_left->data);
            node_to_delete->data = data_of_backLeft;
        }
    }


};

#endif //UNTITLED3_BINARYSEARCHTREE_H
