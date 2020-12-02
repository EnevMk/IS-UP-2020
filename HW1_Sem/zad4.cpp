#include <iostream>
#include <string>

enum class Actions {
    TRANSPOSE,
    FLAT,
    SUM,
    EXIT,
    SUPER,
    HYPER,
    INVALID,
};

//int determinant_Sarus(int rows, int cols, int[][3]);
Actions eval(std::string);
int Pow(int, int);
int determ(int a[][50],int n);
//cubic matrixes do compose linear maps. The 8 axioms concerning the operations sum of two vectors and multiplication a vector with a number 
// are fulfilled. a linear map is defined over some field F.

// 1) summing is asociative - (a + b) + c = a + (b + c) (a, b, c, - vectors)
// 2) summing is commutative - a + b = b + a
// 3) There is a neutral element regarding the operation addition - the vector 0, such that a + 0 = a. Zero-th vector, it is unique.
// 4) for every vector 'a' from the linear map V exist an opposite vector '-a', such that a + (-a) = 0.
// 5) for every vector 'a' it is valid that 1 * a = a.
// 6) for every two numbers 'v' and 't' from the field F over which V is defined, it is valid that (v + t)*a = v*a + t*a.
// 7) for every number 'v' from the field F and for every two vectors 'a' and 'b' from V it is valid that v*(a + b) = v*a + v*b.
// 8) for every two numbers 'v' and 't' from the field F and for every vector 'a' from V it is valid that v*(t*a) = (v*t)*a.
int main() {
    int dim, rows, cols;
    std::cin >> dim >> rows >> cols;

    int matrix[dim][rows][cols];
    int sum_of_dets;

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < rows; ++j) {

            for (int s = 0; s < cols; ++s) {
                std::cin >> matrix[i][j][s];
            }
        }
    } 
    std::cout << "Cubic matrix is saved.\n";
    std::cout << "The program recognizes the following commands: sum, transpose, flat, super, hyper, exit.\n\n";
    std::cout << "Enter command:\n";
    std::string command;
    std::cin >> command;

    while(eval(command) != Actions::EXIT) {
        if(eval(command) == Actions::INVALID) {
            std::cout << "Invalid command. Try again.\n";
            std::cin >> command;
            continue;
        }
        else if (eval(command) == Actions::SUM) {
            for (int i = 0; i < dim; ++i) {
                for (int j = 0; j < rows; ++j) {

                    for (int s = 0; s < cols; ++s) {
                        std::cout << matrix[i][j][s] + matrix[i][j][s] << ' ';
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
            
        }
        else if (eval(command) == Actions::TRANSPOSE) {
            for (int i = dim - 1; i >= 0; --i) {
                for (int j = 0; j < rows; ++j) {

                    for (int s = 0; s < cols; ++s) {
                        std::cout << matrix[i][s][j] << ' ';
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else if (eval(command) == Actions::FLAT) {
            int matrix_2D[rows][cols] = {};

            for (int i = 0; i < dim; ++i) {
                for (int j = 0; j < rows; ++j) {
                    for (int s = 0; s < cols; ++s) {
                        matrix_2D[j][s] += matrix[i][j][s];
                    }
                }
            }
            for (int j = 0; j < rows; ++j) {
                for (int s = 0; s < cols; ++s) {
                    std::cout << matrix_2D[j][s] << ' ';
                }
                std::cout << std::endl;
            }
        }
        else if (eval(command) == Actions::SUPER) {
            int sum = 0;
            for (int i = 0; i < dim; ++i) {
                int new_matrix[50][50] = {0};
                for (int j = 0; j < rows; ++j) {
                    for (int k = 0; k < cols; ++k) {
                        new_matrix[j][k] = matrix[i][j][k];
                    }
                }
                sum += determ(new_matrix, rows);
            }
            std::cout << sum << std::endl;
            
        }
        else if (eval(command) == Actions::HYPER) {
            int prod = 1;
            for (int i = 0; i < dim; ++i) {
                int new_matrix[50][50] = {0};
                for (int j = 0; j < rows; ++j) {
                    for (int k = 0; k < cols; ++k) {
                        new_matrix[j][k] = matrix[i][j][k];
                    }
                }
                prod *= determ(new_matrix, rows);
            }
            std::cout << prod << std::endl;
        }
        
        
        std::cout << "Enter command:\n";
        
        std::cin >> command;
    }
}
Actions eval(std::string cmd) {
    if(cmd == "transpose") {
        return Actions::TRANSPOSE;
    }
    else if (cmd == "sum") {
        return Actions::SUM;
    }
    else if (cmd == "flat") {
        return Actions::FLAT;
    }
    else if (cmd == "super") {
        return Actions::SUPER;
    }
    else if (cmd == "exit"){
        return Actions::EXIT;
    }
    else if (cmd == "hyper") {
        return Actions::HYPER;
    }
    else {
        return Actions::INVALID;
    }
}
int Pow(int base, int power) {
    int prod = 1;
    for (int i = 0; i < power; ++i) {
        prod *= base;
    }
    return prod;
}
int determ(int matrix[][50],int dim) {
    int det=0, rows, cols, temp[50][50];
    if(dim == 1) {
        return matrix[0][0];
    } else if( dim == 2) {
        det = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
        return det;
    } 
    else {
        for(int p = 0 ;p < dim; p++) {
            rows = 0;
            cols = 0;
            for(int i = 1; i < dim ; i++) {
                for (int j = 0; j < dim; j++) {
                    if(j == p) {
                        continue;
                    }
                    temp[rows][cols] = matrix[i][j];
                    cols++;

                    if(cols == dim - 1) {
                        rows++;
                        cols = 0;
                    }
                }
            }
            det = det + matrix[0][p] * Pow(-1, p) * determ(temp, dim - 1);
        }
        return det;
    }
}