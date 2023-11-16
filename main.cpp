#include <iostream>
#include <string>
#include <cmath>
#include "ExpressionEvaluator.h"
#include "Queue.h"
#include "Polynomial.h"
using namespace std;



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



    /*Polynomial p = Polynomial::getFromUser();

    Polynomial p3 = Polynomial::getFromUser();

    p.print();
    p3.print();
    p.calculate(3);
    p.add(p3);
    p.multiply(p3);
    p.print();
    p.multiply(p3);
    p.print();*/ // polynomial


    Queue<int> queue(4);

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
    cout << queue.delete_() << endl ;
    return 0;
}
