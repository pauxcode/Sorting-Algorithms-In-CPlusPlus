#include <random>

void generateArray(int arr[], int length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000);

    for (int i = 0; i < length; ++i) {
        arr[i] = dist(gen);
    }
}