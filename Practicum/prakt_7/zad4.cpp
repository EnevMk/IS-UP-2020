#include <iostream>

enum class Operation {
    REVERSE,
    CHECK,
    NORMALIZE,
    MAP,
    FILTER,
};
void reverse(double*, int);
bool check(double*, int);
void normalize(double[], int&);
void map(double[], int);
void filter(double[], int&);

int main() {
    double arr[50] = {0};
    int size;
    int operation;

    

    std::cin >> size;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    
    std::cin >> operation;
    
    if (operation == 1) {
        reverse(arr, size);
    }
    else if (operation == 2) {
        std::cout << check(arr, size) << std::endl;
    }
    else if (operation == 3) {
        normalize(arr, size);
    }
    else if (operation == 4) {
        std::cout << "enter multiplier: ";
        int multiplier;
        std::cin >> multiplier;
        map(arr, multiplier);
    }
    if (operation == 5) {
        filter(arr, size);
    }

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    
}
void filter(double arr[], int &size) {
    int iterator = 1;
    while (iterator < size) {
        for (int j = iterator; j < size - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = 0;
        --size;
        iterator++;
    }
    
}
void map(double arr[], int num) {
    int size = 0;
    while (arr[size] != 0) {
        ++size;
    }
    std::cout << "size is: " << size << std::endl;

    for (int i = 0; i < size; ++i) {
        arr[i] *= num;
    }
}

void reverse(double* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        *(arr + i) += *(arr + size - 1 - i);
        *(arr + size - 1 - i) = *(arr + i) - *(arr + size - 1 - i);
        *(arr + i) = *(arr + i) - *(arr + size - 1 - i);

    }
}
bool check(double* arr, int size) {
    bool correct = true;
    for (int i = 0; i < size / 2 && correct; i += 2) {
        if (*(arr + 1 + i) != *(arr + i) * 3 || *(arr + i + 2) != *(arr + i + 1) - 5.0) {
            correct = false;
        }
    }
    return correct;
}
void normalize(double arr[], int &size) {
    
    int iterator = 0;
    while (iterator < size) {
        if (arr[iterator + 1] != (arr[iterator] * 3) && size - (iterator + 1) > 0) {

            for(int j = iterator + 1; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = 0;
            --size;
            continue;
        }
        if (arr[iterator + 2] != arr[iterator + 1] - 5 && size - (iterator + 2) > 0) {

            for (int j = iterator + 2; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = 0;
            --size;
            continue;
        }
        else {
            iterator += 2;
        }
        
    }
    //std::cout << arr[0] << ' ' << arr[1];
}