//
// Created by abbasi on ۰۹/۱۱/۲۰۲۳.
//
#ifndef DATASTRUCTURE_POLYNOMIAL_H
#define DATASTRUCTURE_POLYNOMIAL_H
#include <iostream>
#include <cmath>
#include "sort.h"

using namespace std;

struct Term{
    int coeff;
    int ex;

    bool operator==(Term next) const {
        return (this->coeff == next.coeff && this->ex == next.ex);
    }

    bool operator!=(Term next) const {
        return (this->coeff != next.coeff || this->ex != next.ex);
    }

    bool operator<(Term next) const{
        if (this->ex != next.ex) {
            return this->ex < next.ex;
        } else {
            return this->coeff < next.coeff;
        }
    }

    bool operator<=(Term next) const{
        if (this->ex != next.ex) {
            return this->ex <= next.ex;
        } else {
            return this->coeff <= next.coeff;
        }
    }

    bool operator>(Term next) const{
        if (this->ex != next.ex) {
            return this->ex > next.ex;
        } else {
            return this->coeff > next.coeff;
        }
    }

    bool operator>=(Term next) const{
        if (this->ex != next.ex) {
            return this->ex >= next.ex;
        } else {
            return this->coeff >= next.coeff;
        }
    }


};

const Term empty_term = {0, 0};

Term *createArrayOfEmptyTermsWith(int len){
    Term* empty_terms = new Term[len];
    for (int i = 0; i < len; ++i) {
        empty_terms[i].ex = 0;
        empty_terms[i].coeff = 0;
    }
    return empty_terms;
}


class Polynomial {
private:

    int len;
    int firstEmptyTermIndex; // to remain the first term with coefficient 0, and exponent 0;


    void setFirstEmptyTermPosition(){
        /**
         * find the first term with coeff 0, and set its index
         * else first empty term index = len */
        this->firstEmptyTermIndex = this->len;
        for (int i = 0; i < this->len; ++i ) {
            if (this->terms[i].coeff == 0) {
                this->firstEmptyTermIndex = i;
                break;
            }
        }
    }

    void clearTerms(){
        this->setFirstEmptyTermPosition();
        this->len = this->firstEmptyTermIndex;
        Term* clear_terms = new Term[this->firstEmptyTermIndex];
        for (int i = 0; i < this->firstEmptyTermIndex; ++i) {
            clear_terms[i] = this->terms[i];
        }
        delete[] terms;
        this->terms = clear_terms;
    }

public:
    Term* terms;
    Polynomial(Term *terms, int length){
        /**
         * create array of terms with length */
        this->len = length;
        this->terms = createArrayOfEmptyTermsWith(length);

        for (int i = 0; i < length; ++i) {
            if (terms[i].coeff == 0) {
                this->terms[i] = empty_term;
                continue;
            }
            this->terms[i] = terms[i];
        }
        this->sort();
        this->clearTerms();
    }

    Polynomial(int len){
        /**
         * create a Polynomial with len terms which is Initialized ex, coeff to 0*/
        this->len = len;
        this->firstEmptyTermIndex = 0;
        this->terms = createArrayOfEmptyTermsWith(len);

    }

    ~Polynomial() {
        delete[] terms;
    }

    void add(const Polynomial& toAdd_pol){
        /**
         * add each term of this polynomial to toAdd_pol and sort them finally
         * the len of this polynomial would be change to (this-> len + toAdd_pol.len) */

        int new_needed_len = (this->len + toAdd_pol.len);

        Term* result_pol = createArrayOfEmptyTermsWith(new_needed_len);


        int sumOfCoeffs;
        int index_this_poly = 0, index_toAdd_poly = 0, index_result_poly = 0;

        while (index_this_poly < this->len && index_toAdd_poly < toAdd_pol.len) {

            Term &term_of_this_poly = this->terms[index_this_poly];
            Term &term_of_toAdd_poly = toAdd_pol.terms[index_toAdd_poly];
            Term &term_of_result_poly = result_pol[index_result_poly];

            if (term_of_this_poly.ex == term_of_toAdd_poly.ex) {
                if ((sumOfCoeffs = term_of_this_poly.coeff + term_of_toAdd_poly.coeff) != 0) {
                    term_of_result_poly.ex = term_of_this_poly.ex;
                    term_of_result_poly.coeff = sumOfCoeffs;
                    index_result_poly++;
                }
                index_toAdd_poly++;
                index_this_poly++;
            } else if (term_of_this_poly.ex > term_of_toAdd_poly.ex) {
                term_of_result_poly = term_of_this_poly;
                index_result_poly++;
                index_this_poly++;
            } else {
                term_of_result_poly = term_of_toAdd_poly;
                index_toAdd_poly++;
                index_result_poly++;
            }
        }

        while (index_this_poly < this->len) {
            result_pol[index_result_poly] = this->terms[index_this_poly];
            index_result_poly++;
            index_this_poly++;
        }

        while (index_toAdd_poly < toAdd_pol.len) {
            result_pol[index_result_poly] = toAdd_pol.terms[index_toAdd_poly];
            index_result_poly++;
            index_toAdd_poly++;
        }

        delete[] terms;
        this->terms = result_pol;
        this->len = new_needed_len;
        this->clearTerms();
    }

    void multiply(const Polynomial& toMultiply_pol){
        /**
         * change the this polynomial to a simplified and sorted polynomial of multiply of this and toMultiply_pol */

        int new_needed_len = (this->firstEmptyTermIndex * toMultiply_pol.firstEmptyTermIndex);
        // to decrease the space complexity we can use multiply of the first empty term index of both
        // polynomials as the new len for result polynomial

        Term* result_polynomial = createArrayOfEmptyTermsWith(new_needed_len);

        int index_of_result_pol = 0;
        Term term1{}, term2{};
        for (int i = 0; i < this->firstEmptyTermIndex; ++i) {
            term1 = this->terms[i];

            for (int j = 0; j < toMultiply_pol.firstEmptyTermIndex; ++j, ++index_of_result_pol) {
                term2 = toMultiply_pol.terms[j];
                result_polynomial[index_of_result_pol].coeff = term1.coeff * term2.coeff;
                result_polynomial[index_of_result_pol].ex = term1.ex + term2.ex;
            }
        }

        delete[] this->terms;

        // finding same degree terms and add them together
        int sum_of_coeffs;
        for (int i = 0; i < new_needed_len; ++i) {

            if (result_polynomial[i].coeff == 0) continue;
            Term& target_term = result_polynomial[i];

            for (int j = i+1 ; j < new_needed_len; ++j) {
                Term& to_add_term = result_polynomial[j];
                if (to_add_term.coeff != 0 && target_term.ex == to_add_term.ex) {

                    sum_of_coeffs = target_term.coeff + to_add_term.coeff;
                    target_term.coeff = sum_of_coeffs;
                    to_add_term = empty_term;
                }
            }
            if (target_term.coeff == 0) target_term = empty_term;
        }

        this->terms = result_polynomial;
        this->len = new_needed_len;
        this->sort();
        this->clearTerms();
    }


    void sort(){
        /**
         * sort polynomial according to exponents in descending order */
        Sort<Term>::mergeSort(this->terms, this->len-1);
        this->setFirstEmptyTermPosition();
    }

    void print(){
        for (int i = 0; i < this->len; ++i) {
            cout << "(" << this->terms[i].coeff << "x^" << this->terms[i].ex << ") +";
        }
        cout << "\b\b";
        cout << "   the first empty index : " << this->firstEmptyTermIndex << endl;
        cout << " len: " << this->len << endl;

    }

    static Polynomial getFromConsole(){
        /**
         * get data from console for a Polynomial and returns it */

        cout << " Enter the length of terms of your Polynomial: ";
        int length;
        cin >> length;

        Polynomial p(length);

        for (int i = 0; i < length; ++i) {
            cout << "Term " << i+1 << ":" << endl;
            cout << "coefficient: ";
            cin >> p.terms[i].coeff;
            cout << "exponent: ";
            cin >> p.terms[i].ex;
            p.firstEmptyTermIndex++;
        }
        p.sort();
        p.setFirstEmptyTermPosition();

        return p;
    }

    int calculate(int x){
        /**
         * replace the x variable in polynomial, calculate and returns the result */

        int result = 0;
        int term_result;
        for (int i = 0; i < this->firstEmptyTermIndex ; ++i) {
            term_result = (int) pow(x, this->terms[i].ex);
            term_result *= this->terms[i].coeff;
            result += term_result;
        }

        cout << " calculate polynomial:" << endl;
        this->print();
        cout << " x = " << x << " result = " << result << endl;
        return result;
    }
};


#endif //DATASTRUCTURE_POLYNOMIAL_H
