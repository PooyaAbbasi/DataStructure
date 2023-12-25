//
// Created by abasiy on ۲۲/۱۲/۲۰۲۳.
//

#ifndef UNTITLED3_SORT_H
#define UNTITLED3_SORT_H

template <class T>
class Sort{
public:

    static void merge(T *main_arr, int low, int mid, int high){
        int len1 = mid - low + 1;
        int len2 = high - mid;
        int i, j, main_arr_index;


        T* arr_1 = new T[len1];
        T* arr_2 = new T[len2];

        for (i = 0; i < len1; i++)
            arr_1[i] = main_arr[low + i];
        for (j = 0; j < len2; j++)
            arr_2[j] = main_arr[mid + 1 + j];

        i = 0;
        j = 0;
        main_arr_index = low;
        while (i < len1 && j < len2) {
            if (arr_1[i].ex >= arr_2[j].ex) {
                main_arr[main_arr_index] = arr_1[i];
                i++;
            } else {
                main_arr[main_arr_index] = arr_2[j];
                j++;
            }
            main_arr_index++;
        }

        while (i < len1) {
            main_arr[main_arr_index] = arr_1[i];
            i++;
            main_arr_index++;
        }

        while (j < len2) {
            main_arr[main_arr_index] = arr_2[j];
            j++;
            main_arr_index++;
        }

        delete[] arr_1;
        delete[] arr_2;
    }

    static void mergeSort(T *array, int low, int high){
        if (low < high) {
            int mid = (high - low) /2 ;

            mergeSort(array, low, mid);
            mergeSort(array, mid + 1, high);

            Sort::merge(array, low, mid, high);
        }
    }

    static void insertionSort(T *arr, int len){
        int i = 1; // start from element which have at least one element before itself.

        for (; i < len; i++) {
            if (arr[i] < arr[i - 1]) {
                int j = i;
                while (j > 0 && arr[j] < arr[j -1]) {
                    swap(arr, j, j - 1);
                    j--;
                }
            }
        }
    }


    static void quickSort(T *arr, int low, int high){
        if (low < high) {
            int pivot = arr[low];
            int i = low + 1;
            int j = high;

            while (true) {
                while (arr[i] < pivot && i <= j) i++;
                while (arr[j] > pivot && i <= j) j--;

                if (i >= j) break;
                swap(arr, i, j);
            }
            swap(arr, j, low); // low is the very index of pivot
            quickSort(arr, low, j - 1);
            quickSort(arr, j + 1, high);
        }
    }


    static void swap(T *arr, int i, int j){
        T buffer = arr[i];
        arr[i] = arr[j];
        arr[j] = buffer;
    }

};

#endif //UNTITLED3_SORT_H
