#include "../sortingAlgorithms.h"

int partition(int arr[], int low, int high) {
    int left, right, pivot = arr[low];
    left = low;
    right = high;
    while (left < right) {
        while (arr[left] <= pivot) ++left;
        while (arr[right] > pivot) --right;
        if (left < right) swap(arr, left, right);
    }
    arr[low] = arr[right];
    arr[right] = pivot;
    return right;
}

void quickSort(int arr[], int low, int high) {
    int pivot;
    if (high > low) {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}