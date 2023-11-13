//
// Created by abasiy on ۰۹/۱۱/۲۰۲۳.
//
#ifndef UNTITLED3_POLYNOMIAL_H
#define UNTITLED3_POLYNOMIAL_H
#include <iostream>

using namespace std;

struct Term{
    int coeff;
    int ex;
};

const Term empty_term = {0, 0};

Term *createEmptyArrayOfTermsWith(int len){
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
    int lastEmptyTermIndex;
    Term* terms;

    void setLastEmptyTermPosition(){
        this->lastEmptyTermIndex = this->len;
        for (int i = 0; i < this->len; ++i ) {
            if (this->terms[i].coeff == 0) {
                this->lastEmptyTermIndex = i;
                break;
            }
        }
    }


public:

    Polynomial(Term *terms, int length){
        /**
         * create array of terms with length */
        this->len = length;
        this->terms = createEmptyArrayOfTermsWith(length);

        for (int i = 0; i < length; ++i) {
            if (terms[i].coeff == 0) {
                this->terms[i] = empty_term;
                continue;
            }
            this->terms[i] = terms[i];
        }
        this->sort();
        this->setLastEmptyTermPosition();
    }

    Polynomial(int len){
        /**
         * create a Polynomial with len terms which is Initialized ex, coeff to 0*/
        this->len = len;
        this->lastEmptyTermIndex = 0;
        this->terms = createEmptyArrayOfTermsWith(len);

    }

    ~Polynomial() {
        delete[] terms;
    }

    void add(const Polynomial& toAdd_polynomial){
        /**
         * add each term of this polynomial to toAdd_polynomial and sort them finally
         * the len of this polynomial would be change to (this-> len + toAdd_polynomial.len) */

        int new_needed_len = (this->len + toAdd_polynomial.len);

        Term* new_polynomial = createEmptyArrayOfTermsWith(new_needed_len);
        for (int i = 0; i < this->lastEmptyTermIndex; ++i) {
            new_polynomial[i] = this->terms[i];
        }
        delete[] terms;
        this->terms = new_polynomial;
        this->len = new_needed_len;

        int index_of_match_term;
        int sumOfCoeffs;
        for (int i = 0; i < toAdd_polynomial.lastEmptyTermIndex ; ++i) {

            Term &to_add_term = toAdd_polynomial.terms[i];
            index_of_match_term = this->findTermAccordingToExponential(to_add_term.ex);

            if (index_of_match_term != -1) {
                sumOfCoeffs = new_polynomial[index_of_match_term].coeff + to_add_term.coeff;
                if ( sumOfCoeffs != 0){
                    new_polynomial[index_of_match_term].coeff = sumOfCoeffs;
                } else {
                    new_polynomial[index_of_match_term] = empty_term;
                }

            } else {
                new_polynomial[this->lastEmptyTermIndex] = to_add_term;
                this->lastEmptyTermIndex++;
            }
        }

        this->sort();
        this->setLastEmptyTermPosition();
    }


    int findTermAccordingToExponential(int exponential){
        int left = 0;
        int right = this->lastEmptyTermIndex;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (terms[mid].ex == exponential) {
                return mid;
            }
            if (terms[mid].ex > exponential) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // return -1 if the term is not found
    }

    void static merge(Term* maineTerms, int low, int mid, int high) {
        int i, j, main_terms_index;
        int len1 = mid - low + 1;
        int len2 = high - mid;

        Term* terms1 = new Term[len1];
        Term* terms2 = new Term[len2];

        for (i = 0; i < len1; i++)
            terms1[i] = maineTerms[low + i];
        for (j = 0; j < len2; j++)
            terms2[j] = maineTerms[mid + 1 + j];

        i = 0;
        j = 0;
        main_terms_index = low;
        while (i < len1 && j < len2) {
            if (terms1[i].ex >= terms2[j].ex) {
                maineTerms[main_terms_index] = terms1[i];
                i++;
            } else {
                maineTerms[main_terms_index] = terms2[j];
                j++;
            }
            main_terms_index++;
        }

        while (i < len1) {
            maineTerms[main_terms_index] = terms1[i];
            i++;
            main_terms_index++;
        }

        while (j < len2) {
            maineTerms[main_terms_index] = terms2[j];
            j++;
            main_terms_index++;
        }

        delete[] terms1;
        delete[] terms2;
    }

    void static mergeSort(Term* maineTerms, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;

            mergeSort(maineTerms, low, mid);
            mergeSort(maineTerms, mid + 1, high);

            merge(maineTerms, low, mid, high);
        }
    }

    void sort(){
        mergeSort(this->terms, 0, this->len-1);
        this->setLastEmptyTermPosition();
    }

    void print(){
        for (int i = 0; i < this->len; ++i) {
            cout << "(" << this->terms[i].coeff << "x^" << this->terms[i].ex << ") +";
        }
        cout << "\b\b";
        cout << "the last empty index :" << this->lastEmptyTermIndex << endl;
    }

    static Polynomial getFromUser(){
        /**
         * get data from console for a Polynomial and returns it */

        cout << " Enter the length of Polynomial: ";
        int length;
        cin >> length;

        Polynomial p(length);

        for (int i = 0; i < length; ++i) {
            cout << "Polynomial " << i+1 << ":" << endl;
            cout << "exponent: ";
            cin >> p.terms[i].ex;
            cout << "coefficient: ";
            cin >> p.terms[i].coeff;
            p.lastEmptyTermIndex++;
        }
        p.sort();
        p.setLastEmptyTermPosition();

        return p;
    }

};


#endif //UNTITLED3_POLYNOMIAL_H
