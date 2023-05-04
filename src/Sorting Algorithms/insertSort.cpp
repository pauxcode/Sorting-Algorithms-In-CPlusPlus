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