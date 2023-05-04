#include <iostream>
#include "sortingAlgorithms.h"

using std::cout;
using std::cin;

int main() {
    int op;

    int arr[50];
    int length = sizeof arr / sizeof arr[0];

    cout << "Welcome to my program with which you will be able to sort an array with different sorting algorithms.\n";

    while (true) {
        cout << "Which algorithm do you want to use?\n";
        cout << "1) Bubble Sort\n";
        cout << "2) Quick Sort\n";
        cout << "3) Insert Sort\n";
        cout << "4) Merge Sort\n";
        cout << "5) Exit\n";
        cin >> op;

        if (op == 5) {
            cout << "Bye bye see u later :D";
            return 0;
        }

        generateArray(arr, length);
        //int arr[10] = {2,4,6,8,10,1,3,5,7,9};
        int arrTemp[1000];
        //int length = sizeof arr / sizeof arr[0];
        printArray(arr, length, "Array unsorted");

        switch (op) {
            case 1:
                bubbleSortImproved(arr, length);
                break;
            case 2:
                quickSort(arr, 0, length - 1);
                break;
            case 3:
                insertSort(arr, length);
                break;
            case 4:
                mergeSort(arr, arrTemp, 0, length - 1);
                break;
            default:
                cout << "Option not valid :( \n";
                break;
        }

        printArray(arr, length, "Array sorted");
    }
}