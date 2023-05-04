#include <iostream>
#include <string>

using std::cout;

void printArray(int arr[], int length, const std::string &name) {
    cout << name << "\n";
    for (int i = 0; i < length; ++i) {
        cout << "|" << arr[i] << "|";
    }
    printf("\n");
}