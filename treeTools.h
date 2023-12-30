//
// Created by abasiy on ۲۶/۱۱/۲۰۲۳.
//

#ifndef DATASTRUCTURE_TREETOOLS_H
#define DATASTRUCTURE_TREETOOLS_H
#include "BinaryTree.h"
#include "Tree.h"
#include "BinaryNode.h"
#include "TreeNode.h"
#include "LinkList.h"


/**
 * Implementing sibling Tree.
 * remake a Binary tree from a simple (or general) tree recursively.
 * */
template <class T>
void remakeBinaryTreeFromSimpleTreeRecursive(BinaryNode<T> *binaryRoot, TreeNode<T> *simpleTreeRoot){

    if (!simpleTreeRoot->isLeaf()) {
        TreeNode<T> *leftSimpleChild = simpleTreeRoot->getChildren().getAt(0);
        binaryRoot->setLeftChild(leftSimpleChild->getValue());
        remakeBinaryTreeFromSimpleTreeRecursive(binaryRoot->getLeftChild(), leftSimpleChild);
    }

    TreeNode<T> *next_sibling = simpleTreeRoot->nextSibling();
    if (next_sibling != nullptr) {
        binaryRoot->setRightChild(next_sibling->getValue());
        remakeBinaryTreeFromSimpleTreeRecursive(binaryRoot->getRightChild(), next_sibling);
    }

}

template<class T>
BinaryTree<T> remakeBinaryTreeFromSimple(Tree<T> simple_tree){
    BinaryTree<T> binary_tree(simple_tree.root->getValue());
    remakeBinaryTreeFromSimpleTreeRecursive(binary_tree.root, simple_tree.root);
    return binary_tree;
}

#endif //DATASTRUCTURE_TREETOOLS_H
