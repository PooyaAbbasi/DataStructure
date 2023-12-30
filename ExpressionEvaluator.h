//
// Created by abasiy on ۰۴/۱۱/۲۰۲۳.
//

#ifndef DATASTRUCTURE_EXPRESSIONEVALUATOR_H
#define DATASTRUCTURE_EXPRESSIONEVALUATOR_H


#include <string>
#include "Stack.h"


using namespace std;

bool is_operator(char ch);
bool is_operator_or_openParentheses(char ch);
int numOfOpenParenthesesOf(string &exp);
int getNumOfOperators(string &exp);
int get_num_of_char_vars_and_values(string &exp);
void to_post_fix(string expression, char *postfix);
void set_values_array(const char *postfix, int *values);
int get_result_of_statement(int first_var, int second_var, char operation);
int postfixToResult(char *postfix, int* values, int num_of_vars);
int get_num_of_vars(string &exp);

#endif //DATASTRUCTURE_EXPRESSIONEVALUATOR_H
