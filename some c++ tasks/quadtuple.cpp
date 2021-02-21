#include <iostream>

bool quadTuple(double arr[], int n, int sum, int count);

int main() {

    int count;
    double sum;
    std::cin >> count;

    double *arr = new double[count];

    for (int i = 0; i < count; ++i) {

        std::cin >> arr[i];
    }
    std::cout << "Now enter desired sum: ";
    std::cin >> sum;
    
    std::cout << '\n' << quadTuple(arr, count, sum, 0);
    
    return 0;
}
bool quadTuple(double arr[], int n, int sum, int count)
{
    // if the desired sum is reached with 4 elements, return true
    if (sum == 0 && count == 4) {
        return true;
    }
 
    // return false if the sum is not possible with the current configuration
    if (count > 4 || n == 0) {
        return false;
    }
 
    // Recur with
    // 1. Including the current element
    // 2. Excluding the current element
 
    return quadTuple(arr, n - 1, sum - arr[n - 1], count + 1) ||
            quadTuple(arr, n - 1, sum, count);
}
