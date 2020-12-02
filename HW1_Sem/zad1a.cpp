#include <iostream>
#include <string>

enum class Order {
    ASCENDING_ORDER,
    DESCENDING_ORDER,
    ERROR
};

Order eval(std::string);
void sort(Order, int, int[]);

int main() {
    int array[100];
    int n;
    std::string message;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::cin >> message;

    sort(eval(message), n, array);

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << ' ';
    }
    
}

Order eval(std::string msg) {
    if (msg == "ascending") {
        return Order::ASCENDING_ORDER;
    }
    else if (msg == "descending") {
        return Order::DESCENDING_ORDER;
    }
    else {
        return Order::ERROR;
    }
}
void sort(Order ord, int count, int arr[]) {
    if (ord == Order::ASCENDING_ORDER) {

        for (int i = 0; i < count - 1; i++) {
            
            for (int j = i + 1; j < count; j++) {

                if (arr[j] < arr[i]) {
                    
                    arr[j] += arr[i];
                    arr[i] = arr[j] - arr[i];
                    arr[j] -= arr[i];
                }
            }
        }
    }
    else if (ord == Order::DESCENDING_ORDER) {

        for (int i = 0; i < count - 1; i++) {
            
            for (int j = i + 1; j < count; j++) {

                if (arr[j] > arr[i]) {
                    
                    arr[j] += arr[i];
                    arr[i] = arr[j] - arr[i];
                    arr[j] -= arr[i];
                }
            }
        }
    }
    else {
        std::cout << "Message was not recognized. Array was not sorted.\n";
    }
}