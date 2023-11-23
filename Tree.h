//
// Created by abasiy on ۲۱/۱۱/۲۰۲۳.
//

#ifndef UNTITLED3_TREE_H
#define UNTITLED3_TREE_H

#include "TreeNode.h"

template <class T>
class Tree {
private:

    static void print_recursive(TreeNode<T> *node){

        if (node->isLeaf()) {
            return;
        } else {
            cout<< node->getValue() << " : " << " { " ;

            for (int i = 0; i < node->getChildren().length(); ++i) {
                cout << node->getChildren().getAt(i)->getValue() << ", ";
            }
            cout << "}" << endl;

            for (int i = 0; i < node->getChildren().length(); ++i) {
                print_recursive(node->getChildren().getAt(i));
            }
        }
    }

    static int getHeight(TreeNode<T> *node){
        if (node->isLeaf()) {
            return 0;
        } else {

            int max_height_of_children = 0;
            int height_of_each_child;
            for (int i = 0; i < node->getChildren().length() ; ++i) {
                height_of_each_child = getHeight(node->getChildren().getAt(i));
                if (max_height_of_children < height_of_each_child) {
                    max_height_of_children = height_of_each_child;
                }
            }
            return max_height_of_children + 1; // + one for this node which is parsing.
        }
    }


public:

    TreeNode<T>* root;

    Tree(T root_value){
        this->root = new TreeNode<T>(root_value);
    }

    static int get_size_of(TreeNode<T>* node){
        if (node->isLeaf()) {
            return 1;
        } else {
            int size_ = 1;
            for (int i = 0; i < node->getChildren().length(); ++i) {
                size_ += get_size_of(node->getChildren().getAt(i));
            }
            return size_;
        }
    }

    int size(){
        return get_size_of(this->root);
    }

    int height() {
        return getHeight(this->root);
    }

    void print(){
        print_recursive(this->root);
    }

};

#endif //UNTITLED3_TREE_H