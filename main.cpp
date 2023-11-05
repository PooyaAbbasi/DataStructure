#include <iostream>
#include <string>
#include <cmath>
#include "ExpressionEvaluator.h"

#define size_l1 6
#define size_l2 4
#define size_l 10
using namespace std;

/*
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
*/


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


    string exp = "(3*(a+((c/2)^2)))";
    int size_exp = (int) exp.length();

    int num_of_operators = getNumOfOperators(exp);
    int num_of_vars = get_num_of_vars(exp);
    int size_postfix = num_of_operators + num_of_vars;
    char postfix[size_postfix];


    to_post_fix(exp, postfix);

    // print final postfix expression
    for (char c: postfix) {
        cout << c;
    }

    int values[num_of_vars];
    determine_values_of_vars_in(postfix, values);


    for (int c: values) {
        cout << c << endl;
    } // print values array
    // infix to postfix

    int result = prefix_to_result(postfix, values, num_of_vars, size_postfix);

    cout << "result is : " << result << endl;

    return 0;
}
