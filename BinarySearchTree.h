//
// Created by abasiy on ۱۰/۱۲/۲۰۲۳.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

#include "BinaryTree.h"
#include "BinarySearchNode.h"

template<class T>
class BinarySearchTree {
    /**
     * The `BinarySearchTree` class is a template class that implements a binary search tree data structure.
     * Each node in the tree contains a data element of a generic type `T`.
     * This is a threaded tree which use the empty (nullptr) children as threads.
     * Right thread points to the next node of that in in-order travers,
     * and the left points to previous node in in-order travers.
     */
private:
    BinarySearchNode<T> *root;

public:

    BinarySearchTree(T root_data) {
        this->root = new BinarySearchNode<T>(root_data);
    }

    /**
     * Default constructor */
    BinarySearchTree() {
        this->root = nullptr;
    }


    /**
     *  This is a helper method that recursively calculates the height of the subtree rooted at `node`.
     *  */
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

    /**
     *  This is a helper method that recursively calculates the number of nodes in the subtree rooted at `node`.
     *  */
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

    /**
     * This method returns an array containing the elements of the binary search tree in in-order sequence.
     * */
    T *LVR() {
        T *lvr = new T[this->size()];
        T *pointer_of_lvr = lvr;
        getLVRrecursive(this->root, pointer_of_lvr);
        return lvr;
    }

    /** This is a helper method that recursively populates the `lvr` array with the elements of the subtree
     * rooted at `node` in in-order sequence.
     * */
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

    /**
     * This method prints the elements of the binary search tree
     * recursively in depth first order
     * and their left and right children (or threads).
     * */
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

    /**
     * This method inserts a new node with the given data into the binary search tree.
     * If the tree is empty, it creates a new root node.
     * Otherwise, it calls the `insertRecursive` method to find the correct location for the new node.
     * */
    void insert(T data) {
        if (this->root == nullptr) {
            this->root = new BinarySearchNode<T>(data);
        } else {
            this->insertRecursive(data, this->root);
        }
    }

    /**
     * A helper method that recursively finds the correct location for a new node in the subtree rooted at `root`
     * and inserts the new node at that location. It also sets the right and left threads for the new node.
     * */
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

    /**
     *  This method returns the smallest element in the binary search tree.*/
    T front(){
        return frontOf(this->root)->data;
    }

    /**
     * This is a helper method that finds the most left node in tree, which is the smallest element
     * in the subtree rooted at `node`.
     * */
    BinarySearchNode<T> *frontOf(BinarySearchNode<T> *node) {
        while (node->hasLeftChild()) {
            node = node->getLeftChild();
        }
        return node;
    }

    /**
     *  This method returns the largest element in the binary search tree.
     *  */
    T back(){
        return this->backOf(this->root)->data;
    }

    /**
     * This is a helper method that finds the rightest node, which is the largest element
     * in the subtree rooted at `node`.
     * */
    BinarySearchNode<T> *backOf(BinarySearchNode<T> *node) {
        while (node->hasRightChild()) {
            node = node->getRightChild();
        }
        return node;
    }

    /**
     *  This method sets the right thread for a node. If the node does not have a right child,
     *  it finds the in-order successor of the node and sets it as the right thread.
     *  */
    void setRightThread(BinarySearchNode<T> *node) {
        if (!node->hasRightChild()){
            BinarySearchNode<T> *right_thread = nullptr;
            node->setRightThread(findRightThread(node->data, this->root, right_thread));
        }
    }

    /**
     * This is a helper method that finds the in-order successor of a node with `target_data`
     * in the subtree rooted at `root_node`.
     * */
    BinarySearchNode<T> *findRightThread(T target_data,
                                         BinarySearchNode<T> *root_node,
                                         BinarySearchNode<T> *&right_thread) {
        /**
         * The algorithm of finding right (or left) thread is a bit complicated.
         * Next element of this node in in-order travers is the minimum of greater elements among all tree nodes,
         * so in the binary search tree the last node which we go to its left child to get to the target node,
         * is right thread. Because target node is smaller than that
         * and that is the smallest node among nodes are greater than target node.
         * So we have to travers from root of tree to find the target and each time we get to the left child,
         * save the node in 'right_thread' and recall the function.
         * It's done until find the target node we want to find right thread for it.
         * */

        if (target_data == root_node->data) {
            return right_thread;
        } else if (target_data > root_node->data) {
            return findRightThread(target_data, root_node->getRightChild(), right_thread);
        } else {
            right_thread = root_node;
            return findRightThread(target_data, root_node->getLeftChild(), right_thread);
        }
    }

    /**
     *  This method sets the left thread for a node.
     *  If the node does not have a left child,
     *  it finds the in-order predecessor of the node and sets it as the left thread.
     *  */
    void setLeftThread(BinarySearchNode<T> *node) {
        if (!node->hasLeftChild()) {
            BinarySearchNode<T> *left_thread = nullptr;
            node->setLeftThread(this->findLeftThread(node->data, this->root, left_thread));
        }
    }

    /**
     * A helper method that finds the in-order predecessor of a node
     * with `target_data` in the subtree rooted at `root_node`.
     * Algorithm if finding left thread is like right thread, only vice versa;
     * explained in inner docs of 'fineRightThread()' method.
     * */
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

    /**
     *  This method finds a node with `data` in the subtree rooted at `root_node`.
     *  If such a node exists, it returns the node. Otherwise, it returns `nullptr`.
     *  */
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

    /**
     * This method checks whether a node with `data` exists in the binary search tree.
     * It returns `true` if such a node exists and `false` otherwise.
       */
    bool find(T data) {
        return (findNode(data, this->root) != nullptr);
    }


    /**
     * This method removes the node with the given data from the binary search tree.
     * It first finds the node to delete. If such a node does not exist, it prints a message and returns.
     * If the node is a leaf node, it removes the node and updates the parent's child pointer and left thread.
     * If the node has a single child, it replaces the node with its child.
     * If the node has two children, it finds the node with the largest element in the left subtree
     * (i.e., the in-order predecessor), removes that node,
     * and replaces the data of the node to delete with the data of the in-order predecessor.
     * */
    void erase(T data) {
        BinarySearchNode<T> *node_to_delete = this->findNode(data, this->root);

        if (node_to_delete == nullptr) {
            cout << " this node doesn't exist in the tree.";
            return;

        } else if (node_to_delete->isLeaf()) { // leaf node
            BinarySearchNode<T> *parent = node_to_delete->getParent();
            if (parent->getRightChild() == node_to_delete) {
                parent->setIsRightChild(false);
                setRightThread(parent);
            } else {
                parent->setIsLeftChild(false);
                setLeftThread(parent);
            }
            delete node_to_delete;

        } else if (node_to_delete->hasSingleChild()) { // single child
            // assign the value of node_to_delete ptr with one of right or left children
            BinarySearchNode<T> *only_child_of_node_to_delete = ((node_to_delete->hasLeftChild()) ?
                                                                 node_to_delete->getLeftChild() :
                                                                 node_to_delete->getRightChild());
            replaceNodes(node_to_delete, only_child_of_node_to_delete);

        } else { // full node
            BinarySearchNode<T> *back_of_left = this->backOf(node_to_delete->getLeftChild());
            T data_of_backLeft = back_of_left->data;
            erase(back_of_left->data);
            node_to_delete->data = data_of_backLeft;
        }
    }

    /**
     * replace a with b */
    void replaceNodes(BinarySearchNode<T> *a, BinarySearchNode<T> *b){
        b->setParent(a->getParent());

        // determine 'a' is left child of its parent or right child
        if (a->getParent()->getLeftChild() == a) {
            a->getParent()->setLeftChild(b);
        }
        if (a->getParent()->getRightChild() == a) {
            a->getParent()->setRightChild(b);
        }

        // check if the right or left thread of 'b' is 'a' set its thread again
        if (b->getRightThread() == a) {
            setRightThread(b);
        }
        if (b->getLeftThread() == a) {
            setLeftThread(b);
        }

        // delete 'a' at the end
        delete a;
    }


};

#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
