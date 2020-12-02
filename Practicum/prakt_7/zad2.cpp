#include <iostream>

int count_of_digits(char[]);

int main() {
    char niz[] = "   You   can't   9  break   me 7  ";
    std::cout << "There are " << count_of_digits(niz) << " digits in that message.\n";
}

int count_of_digits(char msg[]) {
    int count = 0;
    for (int i = 0; msg[i] != '\0'; ++i) {
        if (msg[i] >= 48 && msg[i] <= 57) {
            count++;
        }
    }
    return count;
}