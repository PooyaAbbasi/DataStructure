//
// Created by abasiy on ۰۱/۱۲/۲۰۲۳.
//
/*
 * breadth first and depth first search of trees (BFS) , (DFS)
 *
 * inorder, preorder, postorder for Binary trees.
 * */

#ifndef DATASTRUCTURE_TRAVERSETREES_H
#define DATASTRUCTURE_TRAVERSETREES_H

#include "BinaryTree.h"
#include "BinaryNode.h"
#include "Tree.h"
#include "TreeNode.h"
#include "Queue.h"
#include "Stack.h"
#include <cmath>

template<class T>
char *getBFSof(Tree<T> tree, int max_child) {
    /*
     * Implementing make the Breadth First search of tree;
     * which the child of tree are in a linked list
     * */

    T *bfs = new T[tree.size() + 1];
    int bfs_index = 0;

    Queue<TreeNode<T> *> queue((int) pow(max_child, tree.height()));
    TreeNode<T> *node;

    for (queue.insert(tree.root); !queue.isEmpty(); bfs_index++) {
        node = queue.delete_();
        bfs[bfs_index] = node->getValue();
        if (!node->isLeaf()) {
            for (Node<TreeNode<T> *> *child_node = node->getChildren().begin();
                 child_node != nullptr;
                 child_node = child_node->nextNode())
            {
                queue.insert(child_node->value());
                // children of each TreeNode is a linked list of pointers of TreeNode<T>
                // the value of child_node is a pointer to a TreeNode<T> object
            }
        }
    }
    bfs[bfs_index] = '\0';
    return bfs;
}


template<class T>
char *getDFSof(Tree<T> tree, int max_child){
    /*
     * Implementing make the Depth First search of tree;
     * which the child of tree are in a linked list
     * */

    T *dfs = new T[tree.size() + 1];
    int dfs_index = 0;
    Stack<TreeNode<T> *> stack(max_child * tree.height());
    TreeNode<T> *node;

    for (stack.push(tree.root); !stack.isEmpty(); dfs_index++) {
        node = stack.pop();
        dfs[dfs_index] = node->getValue();

        if (!node->isLeaf()) {
            for (Node<TreeNode<T> *> *child_node = node->getChildren().end();
                 child_node != nullptr ;
                 child_node = child_node->preNode())
            {
                stack.push(child_node->value());
                // children of each TreeNode is a linked list of pointers of TreeNode<T>
                // the value of child_node is a pointer to a TreeNode<T> object
            }
        }
    }
    dfs[dfs_index] = '\0';
    return dfs;
}


#endif //DATASTRUCTURE_TRAVERSETREES_H
