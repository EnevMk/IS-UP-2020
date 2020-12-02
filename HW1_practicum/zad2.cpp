#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    
    bool powerOf2 = false;

    //binary way of checking whether num is power of 2.
    ((num & num - 1) == 0) ? powerOf2 = true : powerOf2 = false;
    
    if (powerOf2) {
        //finding the power of num
        int stepen = 0;
        int copyOfNum = num;
        while (copyOfNum != 1) {
            copyOfNum /= 2;
            stepen++;
        }

        //finding closest power of 3.
        int prod = 1;
        int diff = num - prod;
        int stepenNa3 = 0;

        for (int i = 0; i <= stepen; i++) {
            prod *= 3;
            if (num > prod) {
                if(num - prod < diff) {
                    diff = num - prod;
                    stepenNa3++;
                }
            }
            else {
                if (prod - num < diff) {
                    diff = prod - num;
                    stepenNa3++;
                }
                else if (prod - num == diff) {
                    cout << num << " -> " << stepenNa3 << ", " << ++stepenNa3 << endl;
                    return 0;
                }
                else {
                    break;
                }
            }
        }
        cout << num << " -> " << stepenNa3 << endl;
        
    }
    // logic for numbers that aren't power of two.
    else {
        int prod = 1;
        int diff = num - prod;
        int stepenNa5 = 0;
        
        //directly finding closest power of 5
        for (int i = 0; i < num; i++) {
            prod *= 5;
            if (num > prod) {
                if (num - prod < diff) {
                    diff = num - prod;
                    stepenNa5++;
                }
            }
            else {
                if (prod - num < diff) {
                    diff = prod - num;
                    stepenNa5 ++;
                }
                else if (prod - num == diff) {
                    cout << num << " -> " << stepenNa5 << ", " << ++stepenNa5 << endl;
                    return 0;
                }
                else{
                    break;
                }
            }
        }
        cout << num << " -> " << stepenNa5 << endl;
        
    }

}