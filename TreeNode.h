//
// Created by abasiy on ۲۱/۱۱/۲۰۲۳.
//
#include "LinkList.h"

#ifndef UNTITLED3_TREENODE_H
#define UNTITLED3_TREENODE_H

template <class T>
class TreeNode {
private:
    TreeNode<T>* parent;
    LinkList<TreeNode<T>*> children;
    T value;

public:
    TreeNode(T value, TreeNode<T> *parent = nullptr){
        this->parent = parent;
        this->children = LinkList<TreeNode<T>*>();
        this->value = value;
    }

    TreeNode<T>* popLeftChild(){
        return children.popFront();
    }

    bool isLeaf(){
        return children.isEmpty();
    }

    void setChildren(LinkList<TreeNode<T> *> list_of_children){
        this->children = list_of_children;
    }

    void pushChildRight(TreeNode<T> *child_ptr){
        this->children.pushEnd(child_ptr);
    }

    void pushChildRight(T data){
        this->children.pushEnd(new TreeNode<T>(data, this));
    }

    void pushChildLeft(TreeNode<T> *child_ptr){
        this->children.pushFront(child_ptr);
    }
    void pushChildLeft(T data){
        this->children.pushFront(new TreeNode<T>(data, this));
    }


    LinkList<TreeNode<T> *> getChildren() const {
        return children;
    }

    void setParent(TreeNode<T> *new_parent){
        this->parent = new_parent;
    }

    TreeNode<T> *getParent() const {
        return parent;
    }

    void setValue(T new_value){
        this->value = new_value;
    }

    T getValue(){
        return this->value;
    }


};
#endif //UNTITLED3_TREENODE_H
