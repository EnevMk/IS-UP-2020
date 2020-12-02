#include <iostream>

void reverse(int[], int);
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    reverse(arr, size);
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
}
void reverse(int arr[], int size) {
    int new_arr[50] = {0};
    for(int i = 0; i < size; ++i) {
        new_arr[i] = arr[size - 1 - i];
    }
    for(int i = 0; i < size; ++i) {
        arr[i] = new_arr[i];
    }
}