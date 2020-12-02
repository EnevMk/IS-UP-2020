#include <iostream>

bool is_valid_identifier(char[]);

int main() {

    char var[] = "p@am";
    std::cout << is_valid_identifier(var) << std::endl;
}

bool is_valid_identifier(char name[]) {
    bool is_valid = true;
    if (name[0] != '_' && !(name[0] >= 65 && name[0] <= 90) && !(name[0] >= 97 && name[0] <= 122)) {
        is_valid = false;
    }

    for (int i = 1; name[i] != '\0' && is_valid; ++i) {
        if (!((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || name[i] == '_' || (name[i] >= 48 && name[i] <= 57))) {
            is_valid = false;
        }
    }
    return is_valid;
}