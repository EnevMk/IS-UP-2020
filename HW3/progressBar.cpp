#include <iostream>
#include <cmath>
#include <cstring>


#ifdef _WIN32
    #include <windows.h>
    void sleep(unsigned milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    void sleep(double milliseconds) {
        sleep(milliseconds / 1000.0);
    }
#endif

int strLen(const char*);
char* parseToChar(int, int&);

struct ProgressBar {

    char *arr;
    unsigned short int len;
    double progress = 0.0;
    bool indicator;

    char beginSymbol, endSymbol, progressSymbol, emptySymbol;

    void input(ProgressBar &pb) {
        std::cout << "Length of the array: \n";
        std::cin >> pb.len;

        std::cout << "Display progress in numbers? (1 or 0) \n";
        std::cin >> pb.indicator;

        std::cout << "Begin symbol: \n";
        std::cin >> pb.beginSymbol;

        std::cout << "End symbol: \n";
        std::cin >> pb.endSymbol;

        std::cout << "Progress symbol: \n";
        std::cin >> pb.progressSymbol;

        std::cout << "Empty symbol: \n";
        std::cin >> pb.emptySymbol;
    }
    void indicateProgress(char *arr, int &index, ProgressBar pb) {
    
        int maxIndex = pb.len - 4;
        (index > maxIndex) ? index = maxIndex : 1;
        
        int len_ = 0;
        int prog = pb.progress * 100;
        char *parsed = parseToChar(prog, len_);
        if (len_ == 3) {
            index = index - 1;
        }
    
        for (int i = 0; i < len_; ++i) {
            arr[index++] = parsed[i];
        }
        arr[index++] = '%';
        delete[] parsed;
    }
    void start(ProgressBar &pb) {
        
        pb.arr = new char[len];
        arr[0] = beginSymbol;
        arr[len - 1] = endSymbol;
        int freePositions = 0;
        if (pb.indicator == 0) {
            freePositions = pb.len - 2;
        }
        else {
            freePositions = pb.len - 5;
        } 
        
        int drawback = 0;
        (indicator == 1) ? drawback = 1 : 1;
        int previousPos = 0;
        double percentage = 100.0 / (pb.len - 2);

        while (progress <= 1.01) {
            std::cout << '\r';
            int index = 1;
            
            double pos = (progress * 100 / percentage) - drawback;
            
            if (pos - previousPos < 1 && progress != 0.0) {
                index += previousPos;
                indicateProgress(arr, index, pb);

                for (int i = 0; i < len; ++i) {
                    std::cout << pb.arr[i];
                }
                
                sleep(350);
                pb.progress += 0.01;

                continue;
            }
            previousPos = floor(pos);
            if (previousPos < 0) previousPos = 0;

            if (pos == len) break;

            for (index = 1; index < pos; ++index) {
                pb.arr[index] = progressSymbol;
                
            }

            if (pb.indicator && progress != 0.0) {
                indicateProgress(arr, index, pb);
            }
            
            for (index; index < len - 1; ++index) {
                pb.arr[index] = emptySymbol;
            }
            
            for (int i = 0; i < len; ++i) {
                std::cout << pb.arr[i];
            }
            sleep(350);
            pb.progress += 0.01;
        }
        delete[] pb.arr;
    }
};

int main() {

    /* ProgressBar bar;
    bar.input(bar);
    bar.start(bar); */
    
    return 0;
}

int strLen(const char *str) {
    if (*str == '\0') return 0;
    return 1 + strLen(str + 1);
}
char* parseToChar(int num, int &lenght) {
    int len = 0;
    int copy = num;
    
    char arr[5];
    while (copy != 0) {        
        char toChar = copy % 10 + '0';

        arr[len++] = toChar;
        copy /= 10;
    }
    char *arrReversed = new char[len];
    lenght = len;
    for (int i = len - 1; i >= 0; --i) {
        arrReversed[len - 1 - i] = arr[i];
    }
    return arrReversed;
}
