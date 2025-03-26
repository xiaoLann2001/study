#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int>& array) {
    for (const auto& n : array)
        cout << n << " ";
    cout << endl;
}

void selectionSort(vector<int>& array) {
    int arraySize = array.size();
    int maxIndex = -1, maxNum = INT32_MIN;
    
    for (int i = 0; i < array.size(); i++) {
        maxIndex = -1, maxNum = INT32_MIN;
        for (int j = 0; j < array.size() - i; j++) {
            if (array[j] > maxNum) {
                maxIndex = j;
                maxNum = array[j];
            }
        }
        if (maxIndex != -1)
            swap(array[maxIndex], array[array.size() - i - 1]);
    }
}

int main() {
    vector<int> nums = {8, 4, 2, 9, 5, 7, 1, 3, 6};

    selectionSort(nums);

    printArray(nums);

    return 0;
}