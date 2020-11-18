#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 3;
    int square[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sum = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == j) {
                sum += square[i][j];
            }
            if (i + j == ROWS - 1) {
                sum += square[i][j];
            }
        }
        
    }
    cout << sum << endl;
    
}