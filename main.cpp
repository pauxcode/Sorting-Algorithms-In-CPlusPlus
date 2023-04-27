#include <iostream>

void printArray(int arr[], int length, const std::string &name) {
    std::cout << name << "\n";
    for (int i = 0; i < length; ++i) {
        printf("|%d|", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int a, int b) {
    arr[a] = arr[a] + arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] = arr[a] - arr[b];
}

void bubbleSort(int arr[], int n) {
    for (int pass = n - 1; pass >= 0; --pass) {
        for (int i = 0; i <= pass - 1 ; ++i) {
            if (arr[i] > arr[i+1]) {
                arr[i] = arr[i] + arr[i+1];
                arr[i+1] = arr[i] - arr[i+1];
                arr[i] = arr[i] - arr[i+1];
            }
        }
    }
}

void bubbleSortImproved(int arr[], int n) {
    int swapped = 1;
    for (int pass = n - 1; pass >= 0 && swapped; --pass) {
        swapped = 0;
        for (int i = 0; i <= pass - 1 ; ++i) {
            if (arr[i] > arr[i+1]) {
                arr[i] = arr[i] + arr[i+1];
                arr[i+1] = arr[i] - arr[i+1];
                arr[i] = arr[i] - arr[i+1];
                swapped = 1;
            }
        }
    }
}

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

void insertSort(int arr[], int n) {
    int j, v;
    for (int i = 1; i < n; ++i) {
        v = arr[i];
        j = i;
        while (arr[j-1] > v && j >= 1) {
            arr[j] = arr[j-1];
            --j;
        }
        arr[j] = v;
    }
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i, left_end, size, temp_pos;
    left_end = mid - 1;
    temp_pos = left;
    size = right - left + 1;
    while ((left <= left_end) && (mid <= right)) {
        if (arr[left] <= arr[mid]) {
            temp[temp_pos] = arr[left];
            temp_pos = temp_pos + 1;
            left = left + 1;
        } else {
            temp[temp_pos] = arr[mid];
            temp_pos = temp_pos + 1;
            mid = mid + 1;
        }
    }
    while (left <= left_end) {
        temp[temp_pos] = arr[left];
        left = left + 1;
        temp_pos = temp_pos + 1;
    }
    while (mid <= right) {
        temp[temp_pos] = arr[mid];
        mid = mid + 1;
        temp_pos = temp_pos + 1;
    }
    for (i = 0; i <= size; ++i) {
        arr[right] = temp[right];
        right = right - 1;
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    if (right > left) {
        mid = (right + left) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid+1, right);
        merge(arr, temp, left, mid+1, right);
    }
}


int main() {
    int arr[10] = {312, 423, 232, 543, 23, 7645,75, 34, 324, 976,};
    // int arr[10] = {0, 1, 2, 3, 4, 5,6, 7, 8, 9,};
    int arr2[10] = {32, 543, 867, 42, 456, 648,789, 123, 345, 64,};
    int arr3[10] = {312, 423, 232, 543, 23, 7645,75, 34, 324, 976,};
    int arr4[10] = {312, 423, 232, 543, 23, 7645,75, 34, 324, 976,};
    int arr5[10] = {312, 423, 232, 543, 23, 7645,75, 34, 324, 976,};
    int arr6[1000];
    int length = sizeof arr / sizeof arr[0];

    printArray(arr, length, "Array 1");
    printArray(arr2, length, "Array 2");
    printArray(arr3, length, "Array 3");
    printArray(arr4, length, "Array 4");
    printArray(arr4, length, "Array 5");

    // Bubble Sort
    bubbleSort(arr, 10);

    // Bubble Sort Improved
    bubbleSortImproved(arr2, length);

    // Quick Sort
    quickSort(arr3, 0, length - 1);

    // Insert Sort
    insertSort(arr4, length);

    // Merge Sort
    mergeSort(arr5, arr6, 0 , length - 1);

    std::cout << std::endl;

    printArray(arr, length, "Post Bubble Sort");
    printArray(arr2, length, "Post Bubble Sort Improved");
    printArray(arr3, length, "Post Quick Sort");
    printArray(arr4, length, "Post Insert Sort");
    printArray(arr5, length, "Post Merge Sort");

    return 0;
}