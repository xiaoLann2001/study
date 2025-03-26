#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int>& array) {
    for (const auto& n : array)
        cout << n << " ";
    cout << endl;
}

void bubbleSort(vector<int>& array) {
    int arraySize = array.size();

    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}

int main() {
    vector<int> nums = {8, 4, 2, 9, 5, 7, 1, 3, 6};

    bubbleSort(nums);

    printArray(nums);

    return 0;
}