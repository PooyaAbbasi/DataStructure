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

    ~TreeNode(){
        for (auto it = this->children.begin() ; it != nullptr ; it = it->nextNode()) {
            delete it;
        }
    };

    TreeNode<T>* popLeftChild(){
        return children.popFront();
    }

    bool isLeaf(){
        return children.isEmpty();
    }

    void setChildren(LinkList<TreeNode<T> *> list_of_children){
        delete this->children;
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


    TreeNode<T> *getParent() const {
        return parent;
    }

    TreeNode<T> *popNextSibling(){
        if (!this->parent->children.isEmpty()) {
            return this->parent->children.popFront();
        } else {
            return nullptr;
        }
    }

    TreeNode<T> *nextSibling(){
        if (this->parent == nullptr) return nullptr;
        LinkList<TreeNode<T> *> sibling = this->parent->getChildren();
        int index_in_sibling = sibling.find(this);
        if (index_in_sibling == -1 || index_in_sibling + 1 == sibling.length()) return nullptr;
        return sibling.getAt(index_in_sibling + 1);
    }

    void setValue(T new_value){
        this->value = new_value;
    }

    T getValue(){
        return this->value;
    }


};
#endif //UNTITLED3_TREENODE_H
