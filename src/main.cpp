#include <iostream>
#include "sortingAlgorithms.h"

int main() {
    int arr[50];
    int length = sizeof arr / sizeof arr[0];

    std::cout << "Welcome to my program with which you will be able to sort an array with different sorting algorithms.\n";

    menu(arr, length);
}