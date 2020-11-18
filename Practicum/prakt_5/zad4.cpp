#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 3;
    int square[ROWS][COLS] = {{1, 2, 3}, {4, 64, 6}, {7, -8, 9}};
    int sum = 0;

    int min = INT16_MAX, max = INT16_MIN;

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {
            if (square[i][j] < min) {
                min = square[i][j];
            }
            else if (square[i][j] > max) {
                max = square[i][j];
            }
        }
        
    }
    cout << min << " " << max << endl;
    
}