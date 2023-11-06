//
// Created by abasiy on ۰۶/۱۱/۲۰۲۳.
//

#include "recursion.h"
#include <iostream>
using namespace std;

void swap(int *array, int index1, int index2) {
    int holder = array[index1];
    array[index1] = array[index2];
    array[index2] = holder;
}

int sort_nozoli(int *arr, int size_of) {
    int max;
    int index_of_max;
    for (int i = 0; i < size_of; ++i) {
        max = arr[i];
        index_of_max = i;
        for (int j = i; j < size_of; ++j) {
            if (arr[j] > max) {
                max = arr[j];
                index_of_max = j;
            }
        }
        swap(arr, i, index_of_max);
    }
    return arr[0];
}


int binary_search(int *array, int start, int end, int target) {
    int mid = (end + start) / 2;
    int mid_item = array[mid];
    if (mid_item == target) {
        return mid;
    } else if (start >= end) {
        return -1;
    } else if (target < mid_item) {
        return binary_search(array, start, (mid - 1), target);
    } else {
        return binary_search(array, (mid + 1), end, target);
    }

}


int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int fibo(int n) {
    if (n == 0) {
//        cout << '$' << endl;
        return 0;
    } else if (n == 1) {
//        cout << '$' << endl;
        return 1;
    } else {
        cout << '$' << endl;
        return fibo(n - 1) + fibo(n - 2);
    }
}


int *recursion_insertion(int arr[], int n, int l) {
    if (n == l) {
        return arr;
    }
    int key = arr[l];
    int j = l - 1;
    while (true) {
        //  int help = arr[j + 1];
        if (j >= 0 && arr[j] < key) {
            arr[j] = key;
            break;
        }
        arr[j + 1] = arr[j];
//        arr[j] = help;
        j--;
    }
    arr[j] = key;
    return recursion_insertion(arr, n, l + 1);
}

