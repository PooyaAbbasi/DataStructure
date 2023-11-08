//
// Created by abasiy on ۰۴/۱۱/۲۰۲۳.
//

#include "ExpressionEvaluator.h"
#include <iostream>
#include <cmath>

bool is_operator(char ch) {
    string operators = "+-*/^%";
    if (operators.find(ch) != string::npos) {
        return true;
    } else
        return false;
    return (operators.find(ch) != string::npos);
}

bool is_operator_or_openParentheses(char ch) {
    return (is_operator(ch) || ch == '(');
}

int numOfOpenParenthesesOf(string &exp) {
    int num_of_parentheses = 0;

    for (char c: exp) {
        if (c == '(') {
            num_of_parentheses++;
        }
    }
    return num_of_parentheses;
}

int getNumOfOperators(string &exp) {
    int num_of_ops = 0;
    for (char c: exp) {
        if (is_operator(c)) {
            num_of_ops++;
        }
    }
    return num_of_ops;
}

int get_num_of_char_vars_and_values(string &exp) {
    int num_of_vars = 0;
    for (char c: exp) {
        if (isalnum(c)) {
            num_of_vars++;
        }
    }
    return num_of_vars;
}


int get_num_of_vars(string &exp){
    int num_of_vars = 0;
    for (int i = 0; i < exp.length(); ++i) {
        if (isalpha(exp[i])) {
            num_of_vars++;
        } else if (isdigit(exp[i])) {

            do i++;
            while (isdigit(exp[i]));
            i--; // because it will be increased in end of loop
            num_of_vars++;
        }
    }
    return num_of_vars;
}


void to_post_fix(string expression, char *postfix) {

    int size_exp = (int) expression.length();

    int num_of_operators = getNumOfOperators(expression);
    int num_of_open_parenthesis = numOfOpenParenthesesOf(expression);

    Stack<char> op_stack(num_of_operators + num_of_open_parenthesis);

    for (int i = 0; i < size_exp; ++i) {
        if (isalnum(expression[i])) {
            *postfix = expression[i];
            postfix++;
        } else if (is_operator_or_openParentheses(expression[i])) {
            op_stack.push(expression[i]);
        } else if (expression[i] == ')') {
            char op_in_stack;
            while ((op_in_stack = op_stack.pop()) != '(') {
                if (is_operator(op_in_stack)) {
                    *postfix = op_in_stack;
                    postfix++;
                }
            }
        }
    }
}

int get_int_value_of(char digit_char){
    return (int) (digit_char - '0');
}


void determine_values_of_vars_in(const char *postfix, int *values) {

    while (*postfix) {
        if (isalpha(*postfix)) {
            cout << "\nenter the value of " << *postfix << " :";
            cin >> *values;
            values++;
        } else if (isdigit(*postfix)) {
            int number = 0;
            do {  // take out the int value of digit chars
                number *= 10;
                number += get_int_value_of(*postfix);
                postfix++;
            } while (isdigit(*postfix));
//            cout << number << endl;
            *values = number;
            values++;
            postfix--; // because postfix will be increased in the end of loop
        }
        postfix++;
    }

}

int get_result_of_statement(int first_var, int second_var, char operation){
    switch (operation) {
        case '+':
            return (first_var + second_var);
        case '-':
            return (first_var - second_var);
        case '*':
            return (first_var * second_var);
        case '^':
            return (int) (pow(first_var, second_var));
        case '/':
            return (int)(first_var / second_var);
        default:
            return NULL;
    }
}

int postfixTOResult(char *postfix, int* values, int num_of_vars, int size_postfix){
    Stack<int> stackInt(num_of_vars);


    while (*postfix) {
        if (isalpha(*postfix)) {
            stackInt.push(*values);
            values ++;
        } else if (is_operator(*postfix)) {
            int second_var = stackInt.pop();
            int first_var = stackInt.pop();

            int result = get_result_of_statement(first_var, second_var, *postfix);
//            cout << "result :" << result << endl;
            stackInt.push(result);
        } else if (isdigit(*postfix)) {
            stackInt.push(*values);
            values++;
            do { // move the postfix ptr to after the digits
                postfix++;
            } while (isdigit(*postfix));
            postfix--; // because postfix will be increased in the end of loop
        }
        postfix++;
    }

    return stackInt.pop();

}

