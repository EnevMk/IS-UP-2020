#include <iostream>
#include <cmath>

void convert_to_binary(int);

int main() {
    int array[100];
    int count;
    std::cin >> count;

    int sum = 0;
    
    for (int i = 0; i < count; ++i) {
        std::cin >> array[i];
    }

    for (int s = 0; s < count; s++) {
        sum += array[s];
    }

    for (int i = 0; i < count; ++i) {
        convert_to_binary(array[i]);
        std::cout << std::endl;    
    }

    std::cout << "Sum in decimal: " << sum << std::endl;
    std::cout << "Sum in binary: "; 
    convert_to_binary(sum);

    std::cout << "\nAvg in decimal: " << sum / count << std::endl;
    std::cout << "Avg in binary: ";
    convert_to_binary(sum / count);
    
}

void convert_to_binary(int n) {

    int binaryReversed[100];
    int iterator = 0;

    while (n != 0) {
        binaryReversed[iterator] = n % 2;
        n /= 2;
        ++iterator;
    }
    
    --iterator;

    for (int j = iterator; j >= 0; --j) {
        std::cout << binaryReversed[j];
    }

}