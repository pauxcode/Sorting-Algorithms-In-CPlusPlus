#include "../sortingAlgorithms.h"

void bubbleSort(int arr[], int n) {
    for (int pass = n - 1; pass >= 0; --pass) {
        for (int i = 0; i <= pass - 1 ; ++i) {
            if (arr[i] > arr[i+1]) swap(arr, i, i+1);
        }
    }
}

void bubbleSortImproved(int arr[], int n) {
    int swapped = 1;
    for (int pass = n - 1; pass >= 0 && swapped; --pass) {
        swapped = 0;
        for (int i = 0; i <= pass - 1 ; ++i) {
            if (arr[i] > arr[i+1]) {
                swap(arr, i, i+1);
                swapped = 1;
            }
        }
    }
}