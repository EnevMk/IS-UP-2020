#include <iostream>
using namespace std;

int main() {
    int matrix[3][5] = 
    {
        {1, 3, 5, 7, 9}, {2, 4, 6, 8, 10}, {3, 4, 5, 6, 7,}
    };
    int sum;


    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += matrix[i][j];
        }
        cout << "sum of " << i << "-th row is " << sum << endl;
    }
    
}