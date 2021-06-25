#include <iostream>
#include <vector>

void sortVector(std::vector<int> &vec) {
    int size_ = vec.size();
    for (int i=1; i < size_; ++i) {

        for (int j = 0 ; j < i; ++j) {

            if (vec[j] < vec[i]) {
                vec[j] += vec[i];
                vec[i] = vec[j] - vec[i];
                vec[j] -= vec[i];
            }
        }
    }
}

bool checkIfCapacityIsEnough(int cap, std::vector<int> vec, int courses, int counter) {

    int size_ = vec.size();
    sortVector(vec);

    int freeCapacity = cap;
    // 26 7 5 4
    for (int i = 0; i < size_; ++i) {

        if (freeCapacity >= vec[i]) {
            freeCapacity -= vec[i];
            vec[i] = 0;
        }
    }

    sortVector(vec);

    int index = size_ -1;
    while (vec[index] == 0) {
        if (vec[index] == 0) vec.pop_back();
        index--;
    }

    if (vec.empty()) return true;

    if (counter >= courses) return false;

    return checkIfCapacityIsEnough(cap, vec, courses, counter+1);


}

int main() {

    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec;

    for (int i = 0; i < n; ++i) {
        int sheepSize;
        std::cin >> sheepSize;
        vec.push_back(sheepSize);
    }

    int sumOfWeights = 0;

    for (int i = 0; i < n; ++i) {
        sumOfWeights += vec[i];
    }

    int minimalRaftCapacity = sumOfWeights / k;
    std::cout << "min: " << minimalRaftCapacity << '\n';
    while (!checkIfCapacityIsEnough(minimalRaftCapacity, vec, k, 1)) {
        minimalRaftCapacity++;
    }
    std::cout << "\nmin capacity needed: " << minimalRaftCapacity;
    //std::cout << "\ntest: " << checkIfCapacityIsEnough(41, vec, k, 1);


    return 0;
}