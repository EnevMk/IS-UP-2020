#include <iostream>
#include <cmath>

int sumOfDigits(int num);
int recStrLen(const char*);
int reversed(int num);
int countOfDigits(int num);
int factorial(int num);
bool areEqual(char*, char*);
int fibonacci(int nth);
int minElement(int *arr, int len);
//za 8 zadacha - 2 funkcii
void printEvaluation(char*);
void evaluate(char *msg, int &capitals, int &small, int &nums);
int toBinary(int num);
void swapcase(char*);

int main() {

    
    char str2[] = "YelloW";
    
    int array[] = {12, 13, 4 ,6, 12};
    swapcase(str2);
    std::cout << str2;
    
    return 0;
}
void swapcase(char *msg) {
    if (*msg == '\0') {
        return;
    }
    if (*msg >= 97 && *msg <= 122) {
        
        *msg -= 32;
    }
    else if (*msg >= 65 && *msg <= 90) {

        *msg += 32;
    }

    return swapcase(msg + 1);
}
int toBinary(int num) {
    
    if (num == 0) {
        return 0;
    }
    return num % 2 + 10 * (toBinary(num / 2));
}
void printEvaluation(char *msg) {
    
    int capitals = 0, small = 0, nums = 0;

    evaluate(msg, capitals, small, nums);

    /* if (*msg == '\0') {
        
        std::cout << "Capital letters: " << capitals
                << "\nSmall letters: " << small
                << "\nNumbers: " << nums; 
              
    }
    if ((int (*msg) >= 65) && (int (*msg) <= 90)) {
        
        ++capitals;
    }
    else if ((*msg >= 97) && (*msg <= 122)) {

        small++;
    }
    else if (*msg >= 48 && *msg <= 57) {

        nums++;
    } */

    std::cout << "Capital letters: " << capitals
            << "\nSmall letters: " << small
            << "\nNumbers: " << nums;
    
}
void evaluate(char *msg, int &capitals, int &small, int &nums) {

    if (*msg == '\0') {
        
        /* std::cout << "Capital letters: " << capitals
                << "\nSmall letters: " << small
                << "\nNumbers: " << nums;  */
        return;        
              
    }
    if ((int (*msg) >= 65) && (int (*msg) <= 90)) {
        
        ++capitals;
    }
    else if ((*msg >= 97) && (*msg <= 122)) {

        small++;
    }
    else if (*msg >= 48 && *msg <= 57) {

        nums++;
    }
    return evaluate(msg + 1, capitals, small, nums);
}
int minElement(int *arr, int len) {

    if (len == 1) {
        return *(arr);
    }   
    return (*arr < minElement(arr + 1, len - 1)) ? *arr : minElement(arr + 1, len - 1);
}
int fibonacci(int nth) {
    
    if (nth == 1 || nth == 2) {
        return 1;
    }
    return fibonacci(nth - 1) + fibonacci(nth - 2);
}
int sumOfDigits(int num) {

    if (num < 10) {
        return num;
    }
    return num % 10 + sumOfDigits(num / 10);
}
int recStrLen(const char *str) {
    
    if (*str == '\0') {
        return 0;
    }

    return 1 + recStrLen(str + 1);

}
int countOfDigits(int num) {
    if (num == 0) {

        return 0;
    }
    
    return 1 + countOfDigits(num / 10);
}
int reversed(int num) {

    if (num < 10) {
        return num;
    }
    return num % 10 * pow(10, countOfDigits(num) - 1) + reversed(num / 10);
}
int factorial(int num) {

    if (num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}
bool areEqual(char *msg1, char *msg2) {

    if (recStrLen(msg1) != recStrLen(msg2)) {
        return false;
    }

    if (*msg1 != *msg2) {
        return false;
    }
    if (*msg1 == '\0' && *msg2 == '\0') {
        return true;
    }
    return areEqual(msg1 + 1, msg2 + 1);
}