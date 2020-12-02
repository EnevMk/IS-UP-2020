#include <iostream>
using namespace std;

int main() {
    int date, month, year;

    cout << "Enter date, month, year in that order: " << endl;
    cin >> date >> month >> year;
    cout << endl;

    bool validDate = true;

    if (year >= 1900 && year <= 2100) {

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (date >= 1 && date <= 31) {

                (date == 31) ? date = 1, month++ : date++;
                (month > 12) ? month -= 12, year++ : 1;
            
            }
            else {
                validDate = false;
            }
        }

        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (date >= 1 && date <= 30) {

                (date == 30) ? date = 1, month++ : date++;
                (month > 12) ? month -= 12, year++ : 1;
            }
            else {
                validDate = false;
            }
        }

        else if (month == 2) {
            bool leapYear = false;

            if (year % 100 == 0 && year % 400 == 0) {
                leapYear = true;
            }
            else if (year % 4 == 0) {
                leapYear = true;
            }
            
            if (leapYear) {
                if (date >= 1 && date <= 29) {

                    (date == 29) ? date = 1, month++ : date++;
                    (month > 12) ? month -= 12, year++ : 1;
            
                }
                else {
                    validDate = false;
                }
            }
            else if (!leapYear) {
                if (date >= 1 && date <= 28) {

                    (date == 28) ? date = 1, month++ : date++;
                    (month > 12) ? month -= 12, year++ : 1;
            
                }
                else {
                    validDate = false;
                }
            }
        }
    }
    else {
        validDate = false;
    }

    if (!validDate) {
        cout << "Invalid date" << endl;
        return 0;
    }

    //string weekdays[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}; // at first I made it with strings

    //stuff below is needed for Zeller's algorithm - this one calculates the day of the week
    int c = year / 100; // first two digits of the year
    int y = year % 100; // last two digits of the year
    int m = month;
    
    // some logic for the day calculating algorithm
    if(m == 1) {
        m = 13;
        y -= 1;
    }
    else if (m == 2) {
        m = 14;
        y -= 1;
    }

    int w = (date + ((13 * (m + 1)) / 5) + y + (y / 4) + (c / 4) + 5 * c); // variable for the weekday;
    w = w % 7;

    //cout << weekdays[w] << " ";

    switch (w)
    {
    case 0:
        cout << "Saturday" << ", ";
        break;
    case 1:
        cout << "Sunday" << ", ";
        break;
    case 2:
        cout << "Monday" << ", ";
        break;
    case 3:
        cout << "Tuesday" << ", ";
        break;
    case 4:
        cout << "Wednesday" << ", ";
        break;
    case 5:
        cout << "Thursday" << ", ";
        break;
    case 6:
        cout << "Friday" << ", ";
        break;
    default:
        break;
    }


    switch (month)
    {
    case 1:
        cout << date << ", " << "January" << ", " << year;
        break;
    case 2:
        cout << date << ", " << "February" << ", " << year;
        break;
    case 3:
        cout << date << ", " << "March" << ", " << year;
        break;
    case 4:
        cout << date << ", " << "April" << ", " << year;
        break;
    case 5:
        cout << date << ", " << "May" << ", " << year;
        break;
    case 6:
        cout << date << ", " << "June" << ", " << year;
        break;
    case 7:
        cout << date << ", " << "July" << ", " << year;
        break;
    case 8:
        cout << date << ", " << "August" << ", " << year;
        break;
    case 9:
        cout << date << ", " << "September" << ", " << year;
        break;
    case 10:
        cout << date << ", " << "October" << ", " << year;
        break;
    case 11:
        cout << date << ", " << "November" << ", " << year;
        break;
    case 12:
        cout << date << ", " << "December" << ", " << year;
        break;
    
    }

}