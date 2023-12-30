//
// Created by abasiy on ۲۳/۱۱/۲۰۲۳.
//

#ifndef DATASTRUCTURE_BINARYNODE_H
#define DATASTRUCTURE_BINARYNODE_H

template <class T>
class BinaryNode {
private:
    BinaryNode<T> * left_child;
    BinaryNode<T> * right_child;
public:
    T data;
    BinaryNode<T> * parent;


    BinaryNode(T data,
               BinaryNode<T> *parent = nullptr,
               BinaryNode<T> *leftChild = nullptr,
               BinaryNode<T> *rightChild = nullptr
               ) {

        this->data = data;
        this->parent = parent;
        this->left_child = leftChild;
        this->right_child = rightChild;
    }

    ~BinaryNode(){
        this->right_child = nullptr;
        this->left_child = nullptr;
        this->parent = nullptr;
    };

    bool isLeaf(){
        return (left_child == nullptr && right_child == nullptr);
    }

    bool hasChild(){
        return (left_child != nullptr || right_child != nullptr);
    }

    void setRightChild(T value){
        if(this->right_child != nullptr) {
            delete this->right_child;
        }
        this->right_child = new BinaryNode<T>(value, this);
    }

    void setLeftChild(T value){
        if(this->left_child != nullptr) {
            delete this->left_child;
        }
        this->left_child = new BinaryNode<T>(value, this);
    }


    BinaryNode<T> *getLeftChild() const {
        return left_child;
    }

    BinaryNode<T> *getRightChild() const {
        return right_child;
    }

};

#endif //DATASTRUCTURE_BINARYNODE_H
