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

    void getLVRrecursive(BinaryNode<T> *node, T* &lvr){
        if (node->getLeftChild() != nullptr) {
            getLVRrecursive(node->getLeftChild(), lvr);
        }

        cout << node->data << "-";
        *lvr = node->data;
        lvr ++;

        if (node->getRightChild() != nullptr) {
            getLVRrecursive(node->getRightChild(), lvr);
        }
    }

    T * LVR(){
        T *lvr = new T[this->size()];
        T *pointer_of_lvr = lvr;
        getLVRrecursive(this->root, pointer_of_lvr);
        return lvr;
    }

    void getVLRrecursive(BinaryNode<T> *node, T* &vlr){
        cout << node->data << "-";
        *vlr = node->data;
        vlr ++;

        if (node->getLeftChild() != nullptr) {
            getVLRrecursive(node->getLeftChild(), vlr);
        }

        if (node->getRightChild() != nullptr) {
            getVLRrecursive(node->getRightChild(), vlr);
        }
    }

    T * VLR(){
        T *vlr = new T[this->size()];
        T *pointer_of_vlr = vlr;
        getVLRrecursive(this->root, pointer_of_vlr);
        return vlr;
    }

    void getLRVrecursive(BinaryNode<T> *node, T* &lvr){
        if (node->getLeftChild() != nullptr) {
            getLRVrecursive(node->getLeftChild(), lvr);
        }

        if (node->getRightChild() != nullptr) {
            getLRVrecursive(node->getRightChild(), lvr);
        }

        cout << node->data << "-";
        *lvr = node->data;
        lvr ++;
    }

    T * LRV(){
        T *lrv = new T[this->size()];
        T *pointer_of_lrv = lrv;
        getLRVrecursive(this->root, pointer_of_lrv);
        return lrv;
    }

    static BinaryTree<T> makeBinaryTreeOf(T *lvr, T *vlr, int len_of_nodes){
        BinaryTree<T> result_tree(*vlr);

        if (len_of_nodes == 1) return result_tree;

        int index_of_root_in_lvr = 0;
        for (; index_of_root_in_lvr < len_of_nodes ; index_of_root_in_lvr++) {
            if (lvr[index_of_root_in_lvr] == *vlr) break;
        }

        setChildRecursive(result_tree.root, 0, index_of_root_in_lvr - 1,
                          lvr, vlr, true);


        setChildRecursive(result_tree.root, index_of_root_in_lvr + 1, len_of_nodes,
                          lvr, vlr, false);

        return result_tree;
    }

    static void setChildRecursive(BinaryNode<T> *root, int low, int high, T* lvr, T* &vlr, bool is_left){
        if (*(vlr + 1) == '\0' || low > high) return;
        char* child = ++vlr;
        (is_left)? root->setLeftChild(*child) : root->setRightChild(*child);

        if (low == high) {
            return;
        } else {

            int index_of_child_in_lvr = low;
            for (; index_of_child_in_lvr <= high; ++index_of_child_in_lvr) {
                if (lvr[index_of_child_in_lvr] == *child) break;
            }
            BinaryNode<T> * new_root = (is_left)? root->getLeftChild(): root->getRightChild();
                setChildRecursive(new_root, low, index_of_child_in_lvr -1,
                                  lvr, vlr, true);

                setChildRecursive(new_root, index_of_child_in_lvr + 1, high,
                                  lvr, vlr, false);
        }
    }

    void addNodesFromConsole(){
        if (this->root == nullptr) {
            T root_value;
            cout << "enter root value: ";
            cin >> root_value;
            this->root = new BinaryNode<T>(root_value);
        }
        int cancel;
        do {
            cout << "the tree :\n ";
            this->print();
            addNodesFromConsoleRecursive(this->root);
            cout << " to cancel enter 0 to continue enter 1: \n";
            cin >> cancel;
        } while (cancel != 0);
    }

    void addNodesFromConsoleRecursive(BinaryNode<T> *root){

        bool has_left = root->getLeftChild() != nullptr;
        bool has_right = root->getRightChild() != nullptr;

        cout << " the root is :" << root->data << endl;
        cout << ((has_left)? "1. get into left.\n " : "1. add left child. \n" );
        cout << ((has_right)? "2. get into right \n" : "2. add right child. \n" );
        int choice;
        cout << "enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (!has_left) {
                T value;
                cout << " enter your value : ";
                cin >> value;
                root->setLeftChild(value);
            } else {
                addNodesFromConsoleRecursive(root->getLeftChild());
            }
        } else {
            if (!has_right) {
                T value;
                cout << " enter your value : ";
                cin >> value;
                root->setRightChild(value);
            } else {
                addNodesFromConsoleRecursive(root->getRightChild());
            }
        }
    }

};

#endif //UNTITLED3_BINARYTREE_H
