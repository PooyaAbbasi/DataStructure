cmake_minimum_required(VERSION 3.23)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure main.cpp
        Stack.h
        ExpressionEvaluator.h
        ExpressionEvaluator.cpp
        recursion.h
        recursion.cpp
        Queue.h
        Polynomial.h
        LinkList.h
        Node.h
        Tree.h
        TreeNode.h
        BinaryNode.h
        BinaryTree.h
        treeTools.h
        traverseTrees.h
        MinHeapTree.h
        BinarySearchTree.h
        BinarySearchNode.h
        sort.h
)
