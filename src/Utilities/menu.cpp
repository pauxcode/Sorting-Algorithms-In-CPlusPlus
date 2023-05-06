#include <iostream>
#include "../sortingAlgorithms.h"

using std::cout;
using std::cin;

void menu(int arr[], int length) {
    int op;

    while (true) {
        cout << "\nWhich algorithm do you want to use?\n";
        cout << "1) Bubble Sort\n";
        cout << "2) Quick Sort\n";
        cout << "3) Insert Sort\n";
        cout << "4) Merge Sort\n";
        cout << "5) Exit\n";
        cout << "> ";
        cin >> op;

        if(!cin) {
            cout << "\nOnly numbers is valid :)\n";
            exit(1);
        }

        if (op == 5) {
            cout << "\nBye bye see u later :D\n";
            exit(0);
        }

        generateArray(arr, length);
        int arrTemp[length];

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