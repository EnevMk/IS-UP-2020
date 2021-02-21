#include <iostream>

void permHelper(char **list, int &index, char *str, int left, int right);
int strCmp(const char *str1, const char *str2);
void permute(char* str, int l, int r);
void swapCase(char &a, char &b);
void strCpy(char *dest, const char *src);
int strLen(const char *str);
void filterArr(char **list, int &len);

struct permutationArray {

    int maxLen = 100;
    char **list = new char*[maxLen];

    void initialize(permutationArray &perm) {
        for (int i = 0; i < maxLen; ++i) {
            perm.list[i] = new char[maxLen];
            perm.list[i][0] = '\0';
        }
    }
    
    void addElement(const char* str, permutationArray &perm) {

        for (int i = 0; i < maxLen; ++i) {
            if (perm.list[i][0] == '\0') {
                strCpy(perm.list[i], str);
                break;
            }
        }
    }
    void printElement(permutationArray &perm) {
        for (int i = 0; i < maxLen; ++i) {

            if (perm.list[i][0] != '\0') {
                std::cout << perm.list[i] << '\n';
            }

            else if (perm.list[i][0] == '\0') break;
        }
    }
};
permutationArray generatePermutations(char *str);

int main() {
    char str[] = "OOP";
    permutationArray structure = generatePermutations(str);
    structure.printElement(structure);

    return 0;
}
void strCpy(char *dest, const char *src) {
    int i;
    for (i = 0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
void permute(char* str, int l, int r) {

    if (l == r) std::cout << str << ' ';

    else {
        for (int i = l; i <= r; ++i) {

            swapCase(str[i], str[l]);
            permute(str, l + 1, r);
            swapCase(str[i], str[l]);
        }
    }
    
}
void filterArr(char **list, int &len) {

    for (int i = 0; i < len - 1; ++i) {

        for (int j = i + 1; j < len; ++j) {

            if(!strCmp(list[i], list[j])) {

                for (int s = j; s < len - 1; ++s) {
                    strCpy(list[s], list[s + 1]);
                }
                len--;
            }
        }
    }
}
permutationArray generatePermutations(char *str) {
    int len = strLen(str);
    int cnt = 1;

    for (int i = 1; i <= len; ++i) {
        cnt *= i;
    }

    char **list = new char*[cnt];
    for (int i = 0; i < cnt; ++i) {
        list[i] = new char[len];
    }

    int ind = 0;
    permHelper(list, ind, str, 0, len - 1);
    filterArr(list, cnt);

    permutationArray pm;
    pm.initialize(pm);
    
    for (int i = 0; i < cnt; ++i) {
        strCpy(pm.list[i], list[i]);
    }

    for (int j = 0; j < cnt; ++j) {
        delete[] list[j];
    }
    delete[] list;

    return pm;
}
void permHelper(char **list, int &index, char *str, int left, int right) {

    if (left == right) {
        strCpy(list[index], str);
        index++;
    }

    else {
        for (int i = left; i <= right; ++i) {
            swapCase(str[i], str[left]);
            permHelper(list, index, str, left + 1, right);
            swapCase(str[i], str[left]);
        }
    }
}
int strLen(const char *str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i) {}
    return i;
}
void swapCase(char &a, char &b) {
    char temp = b;
    b = a;
    a = temp;
}
int strCmp(const char *str1, const char *str2) {
    int i;

    for (i = 0; str1[i] == str2[i]; ++i) {
        if (str1[i] == '\0') return 0;
    }
    /* std::cout << str1[i] << ' ' << str2[i] << '\n';
    std::cout << i; */
    return int(str1[i] - str2[i]);
}
