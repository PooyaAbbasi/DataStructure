#include <iostream>
#include <string>
#include <cmath>
#include "ExpressionEvaluator.h"
#include "Queue.h"
#include "Polynomial.h"
#include "LinkList.h"
#include <vector>
#include "Tree.h"
#include "BinaryTree.h"
#include "treeTools.h"
#include "traverseTrees.h"
using namespace std;

int recursive_determinant(std::vector<std::vector<int>>& matrix) {
    int len_matrix = (int) matrix.size();
    if (len_matrix <= 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        int determinant = 0;
        for (int k = 0; k < len_matrix; ++k) {
            std::vector<std::vector<int>> sub_matrix;
            for (int i = 1; i < len_matrix; ++i) {
                std::vector<int> row;
                for (int j = 0; j < len_matrix; ++j) {
                    if (k != j) {
                        row.push_back(matrix[i][j]);
                    }
                }
                sub_matrix.push_back(row);
            }
            if (k % 2 == 1) {
                determinant -= (matrix[0][k] * recursive_determinant(sub_matrix));
            } else {
                determinant += (matrix[0][k] * recursive_determinant(sub_matrix));
            }
        }
        return determinant;
    }
}

int main() {
    /*int l1[size_l1] = {100, 23, 20, 15, 12, 5};
    int l2[size_l2] = {95, 90, 40, 39};

    int index_l1 = 0;
    int index_l2 = 0;

    int size_output = size_l1 + size_l2;
    int output[size_output];

    for (int i = 0; i < size_output; i++) {
        if (index_l1 < size_l1 && index_l2 < size_l2) {
            if (l1[index_l1] > l2[index_l2]) {
                output[i] = l1[index_l1];
                index_l1++;
            } else if (l2[index_l2] > l1[index_l1]) {
                output[i] = l2[index_l2];
                index_l2++;
            } else {
                output[i] = l1[index_l1];
                i++;
                output[i] = l2[index_l2];
                index_l1++;
                index_l2++;
            }
        } else if (index_l1 < size_l1) {
//            while (index_l1 < size_l1) {
                output[i] = l1[index_l1];
                index_l1++;
//                i++;
//            }
        } else if (index_l2 < size_l2) {
//            while (index_l2 < size_l2) {
                output[i] = l2[index_l2];
                index_l2++;
//                i++;
//            }
        }
    }


    for (int i = 0; i < size_output; ++i) {
        cout << *(output + i) << ' ';
    }*/ // sort_combined_two_array

    /*string exp = "((((22-k)^t)+(80/t))*2)";
    int size_exp = (int) exp.length();

    int num_of_operators = getNumOfOperators(exp);
    int numOfCharVarsAndValues = get_num_of_char_vars_and_values(exp);

    int size_postfix = num_of_operators + numOfCharVarsAndValues;
    char postfix[size_postfix + 1];
    postfix[size_postfix] = '\0';

    to_post_fix(exp, postfix);

    // print final postfix expression
    for (char c: postfix) {
        cout << c;
    }

    int values[get_num_of_vars(exp)];
    set_values_array(postfix, values);

    cout << " \n values in order of post fix variables: \n";
    for (int c: values) {
        cout << c << endl;
    } // print values array
    // infix to postfix

    int result = postfixToResult(postfix, values, numOfCharVarsAndValues);

    cout << "result is : " << result << endl;*/// Expression Evaluation

/*
    Polynomial p= Polynomial::getFromConsole();


    Polynomial p3= Polynomial::getFromConsole();

    p.print();
    p3.print();
    p.calculate(3);
    p.add(p3);
    p.print();
    p.multiply(p3);
    p.print(); */ // polynomial


    /*Queue<int> queue(4);

    queue.insert(5);
    queue.insert(9);
    queue.insert(98);
    cout << queue.delete_() << endl ;
    queue.insert(3);
    queue.insert(8);
    cout << queue.delete_() << endl ;
    cout << queue.delete_() << endl ;
    cout << queue.delete_() << endl ;
    cout << queue.delete_() << endl ;
    cout << queue.delete_() << endl ;*/// Queue execution

/*
    LinkList<int> int_list;

    int_list.pushFront(32);
    int_list.pushFront(5);
    int_list.pushFront(69);
    int_list.pushFront(78);
    int_list.pushFront(78);
    int_list.pushFront(78);

    int_list.eraseNodesWithValue(78);
    int_list.print();
    int_list.eraseNodeAt(1);
    cout << " after erase at 1";
    int_list.print();
    int_list.eraseNodeAt(3);
    cout << " after erase at 3";
    int_list.print();
    int_list.printReverse();
    int_list.eraseNodeAt(3);
    cout << " after erase at 3";
    int_list.print();

 */// LinkedList


    /*Tree<char> tree('A');

    tree.root->pushChildLeft('b');
    tree.root->pushChildRight('c');

    for (int i = 0; i < tree.root->getChildren().length(); ++i) {
        tree.root->getChildren().getAt(i)->pushChildLeft('d');
        tree.root->getChildren().getAt(i)->pushChildLeft('e');
        tree.root->getChildren().getAt(i)->pushChildLeft('f');
    }

    TreeNode<char> *treeNode0 = tree.root->getChildren().getAt(0);
    //cout << "parent of treeNode = b : " << treeNode0->getParent()->getValue() << endl;
    //cout << "next sibling of treeNode = b : " << treeNode0->nextSibling()->getValue() << endl;

    for (int i = 0; i < treeNode0->getChildren().length(); ++i) {
        treeNode0->getChildren().getAt(i)->pushChildLeft('g');
        treeNode0->getChildren().getAt(i)->pushChildLeft('h');
        treeNode0->getChildren().getAt(i)->pushChildLeft('i');
    }

    tree.print();
    //cout << " tree size :" << tree.size() << endl;
    //cout << " tree height :" << tree.height() << endl;

    BinaryTree<int> binaryTree(1);

    binaryTree.root->setLeftChild(2);
    binaryTree.root->setRightChild(3);

    auto right_child = binaryTree.root->getRightChild();
    auto left_child = binaryTree.root->getLeftChild();

    right_child->setRightChild(31);
    right_child->setLeftChild(32);
    //cout << "\n\n binary tree :" << endl;
    //cout << " size of binary tree : " << binaryTree.size() << endl;
    //cout << " height of binary tree : " << binaryTree.height() << endl;

    cout << " \n binary tree: \n";
    binaryTree.print();

    //cout << " the parent of 31: " << right_child->getRightChild()->parent->data << endl;

    BinaryTree<char> remade_binary_tree = remakeBinaryTreeFromSimple(tree);

    //cout << "\n\n remade binary tree :" << endl;
    //remade_binary_tree.print();


    char *bfs_of_tree = getBFSof(tree, 3);
    cout << "\n BFS of tree :" << bfs_of_tree << endl;

    char *dfs_of_tree = getDFSof(tree, 3);
    cout << "\n DFS of tree :" << dfs_of_tree << endl;


    cout << " \n VLR of binary tree: ";
    int *vlr =binaryTree.VLR();
    cout << "\n array of vlr :";
    for (int i = 0; i < binaryTree.size(); ++i) {
        cout << vlr[i] << "-";
    }
    cout << " \n LRV of binary tree: ";
    binaryTree.LRV();
    cout << " \n VLR of binary tree: ";
    binaryTree.VLR();*/


    char lvr_[11] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
    char vlr_[11] = {'G', 'D', 'B', 'A', 'C', 'E', 'F', 'I', 'H', 'J', '\0'};
    BinaryTree<char>::makeBinaryTreeOf(lvr_, vlr_, 10).print();

/*vector<vector<int>> matrix = {
    {1, 1, 1, 0},
    {1, 2, 1, 3},
    {2, 2, 3, 0},
    {2, 3, 0, 0}
    };

////cout << recursive_determinant(matrix);*/ // Test recursive determinant;

    return 0;
}
