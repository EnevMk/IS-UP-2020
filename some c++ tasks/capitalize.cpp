#include <iostream>

void capitalize(char*, int);
int strLen(char*);
int main() {
    const int MAX_LEN = 100;
    char arr[MAX_LEN];
    std::cin.getline(arr, MAX_LEN, '\n');
    
    int len = strLen(arr);
    
    char *string = new char[len];
    for (int i = 0; i < len; ++i) {

        string[i] = arr[i];
    }
    
    capitalize(string, len);
    std::cout << string;

    delete string;
    
    return 0;
}
void capitalize(char *str, int len) {

    for (int i = 0; str[i] != '\0'; ++i) {
        
        if(str[i] == '[') {

            for (int j = i + 1; str[j] != ']'; ++j) {

                if (str[j] >= 'a' && str[j] <= 'z') {

                    str[j] -= 'a' - 'A';
                }
            }

        }
    }

    for (int i = 0; i < len; ++i) {

        if (str[i] == '[' || str[i] == ']') {

            for (int j = i; j < len - 1; ++j) {

                str[j] = str[j + 1];
            }
            len--;
            str[len] = '\0';
        }
    }
    return;
}
int strLen(char *str) {

    if (*str == '\0') return 0;
    return 1 + strLen(str + 1);
}
