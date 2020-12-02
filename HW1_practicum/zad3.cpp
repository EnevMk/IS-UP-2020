#include <iostream>
using namespace std;

int main() {
    const int dayLength = 3;
    const int monthLength = 2;
    const int yrLength = 4;

    char date[dayLength];
    char month[monthLength];
    char yr[yrLength];

    int number;
    
    cin.getline(date, dayLength, '.');
    cin.getline(month, monthLength, '.');
    cin.getline(yr, yrLength, ' ');

    cin >> number;

    //defining array needed for conversion between decimal an the other number system and array length.
    const int arrLength = 14;
    char arr[] = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g' , 'h', 'i', 'j', 'k', 'l', 'm'};

    int power = 0;
    int yearDecimal = 0;
    
    // converting year to decimal below ...
    for (int i = sizeof(yr) - 2; i >= 0; --i) {

        for (int q = 0; q < arrLength; ++q) {
            if (yr[i] == arr[q]) {
                
                if (power == 0) {
                    yearDecimal += q;
                }
                else {
                    int prod = q;
                    for (int p = 1; p <= power; ++p) {
                        prod *= 14;
                    }
                    yearDecimal += prod;
                }
                ++power;
                break;
            }
        }
        
    }
    // some logic for validation...
    
    if (yearDecimal > 2100) {
        cout << "Year too far away." << endl;
        return 0;
    }
    if ((int)month[0] < 97 || (int)month[0] > 108) {
        cout << "Invalid month" << endl;
        return 0;
    }

    // converting month to decimal...
    int monthDecimal = 0;
    power = 0;

    for (int q = 0; q < arrLength; ++q) {
        if (month[0] == arr[q]) {
            monthDecimal = q;
        }
    }

    // converting the date to decimal...
    int dayDecimal = 0;
    power = 0;

    for (int i = sizeof(date) - 1; i >= 0; --i) {

        for (int q = 0; q < arrLength; ++q) {
            if (date[i] == arr[q]) {
                
                if (power == 0) {
                    dayDecimal += q;
                }
                else {
                    int prod = q;
                    for (int p = 1; p <= power; ++p) {
                        prod *= 14;
                    }
                    dayDecimal += prod;
                }
                ++power;
                break;
            }
        }
        
    }

    bool validDate = true;
    if (dayDecimal > 31) {
        validDate = false;
        cout << "Invalid date." << endl;
        return 0;
    }

    if (monthDecimal == 1 || monthDecimal == 3 || monthDecimal == 5 || monthDecimal == 7 
        || monthDecimal == 8 || monthDecimal == 10 || monthDecimal == 12) {

            if (dayDecimal > 31) {
                validDate = false;
            }
    }
    else if(monthDecimal == 4 || monthDecimal == 6 || monthDecimal == 9 || monthDecimal == 11) {

        if (dayDecimal > 30) {
                validDate = false;
            }
    }
    else if (monthDecimal == 2) {
        bool leapYear = false;

        if ((yearDecimal % 4 == 0) && (yearDecimal % 100 != 0 || yearDecimal % 400 == 0)) {
            leapYear = true;
        }

        if (!leapYear) {
            if (dayDecimal > 28) {
                validDate = false;
            }
        }
        else if (leapYear) {
            if (dayDecimal > 29) {
                validDate = false;
            }
        }
    }

    if (!validDate) {
        cout << "Invalid date." << endl;
        return 0;
    }

    // now finding out what weekday it was using Zeller's algorithm.

    int c = yearDecimal / 100; //first two digits of the year
    int y = yearDecimal % 100; //last two digits of the year
    int m = monthDecimal;

    // some logic for the day calculating algorithm
    if(m == 1) {
        m = 13;
        y -= 1;
    }
    else if (m == 2) {
        m = 14;
        y -= 1;
    }

    int w = (dayDecimal + ((13 * (m + 1)) / 5) + y + (y / 4) + (c / 4) + 5 * c); // variable for the weekday;
    w = w % 7;

    // if the day is Saturday or Sunday
    if (w == 0 || w == 1) {
        cout << "Yes, " << dayDecimal << "." << monthDecimal << "." << yearDecimal << " isn't a working day. ";
    }
    else {
        cout << "No, " << dayDecimal << "." << monthDecimal << "." << yearDecimal << " is a working day. ";
    }

    // converting decimal number to the other number system.
    int copy = number;
    int galaxyDate[5];
    int iterator = 0;

    while (copy != 0) {
        galaxyDate[iterator] = copy % 14;
        iterator++;
        copy /= 14;
    }
    // for input 213 the galaxyDate[] will store {3, 1, 1}, iterator = 3;
    cout << number << " -> ";
    for (int s = iterator - 1; s >= 0; --s) {
        cout << arr[galaxyDate[s]];
    }

}