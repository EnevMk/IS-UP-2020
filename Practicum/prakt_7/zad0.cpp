#include <iostream>

void swap_by_reference(int&, int&);
void swap_by_ptr(int*, int*);
int main() {
    int a = 5, b = 7;
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
    /* swap_by_reference(a, b);
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl; */

    int *ptr1 = &a;
    int *ptr2 = &b;

    swap_by_ptr(ptr1, ptr2);
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

}
void swap_by_reference(int &num1, int &num2) {
    num1 += num2;
    num2 = num1 - num2;
    num1 -= num2;
}
void swap_by_ptr(int *num1, int *num2) {
    *num1 += *num2;
    *num2 = *num1 - *num2;
    *num1 -= *num2;
}