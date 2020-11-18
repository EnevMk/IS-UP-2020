#include <iostream>
using namespace std;

int main() {
    const int length = 100;
    int arr[length];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int number;
    cin >> number;
    int indexes[length];
    int indexator = 0;

    int count = 0;

    for (int j = 0; j < n; j++) {
        if (arr[j] == number) {
            ++count;
            indexes[indexator] = j;
            ++indexator;
        }
    }
    
    if (count != 0) {
        cout << "The number " << number << " is met " << count << " times." << endl;
        cout << "These are the indexes that " << number << " is positioned in the array: " << endl;

        for (int i = 0; i < indexator; i++) {
            cout << indexes[i] << endl;
        }
        
    }
    else {
        cout << "The number" << number << " was not found in the array." << endl;
    }
    
}