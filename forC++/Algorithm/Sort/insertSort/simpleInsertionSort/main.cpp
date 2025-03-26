#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int>& array) {
    for (const auto& n : array)
        cout << n << " ";
    cout << endl;
}

void insertionSort(vector<int>& array) {
    int arraySize = array.size();

    // 第一个元素直接加入有序数组
    for (int i = 1; i < array.size(); i++) {
        // 如果 array[i] >= array[i - 1]，直接插入到 array[i - 1] 之后，也就是没有改变
        // 如果 array[i] < array[i - 1]，就需要找到待插入位置，然后将该位置之后的元素后移，再插入
        if (array[i] < array[i - 1]) {
            int j = i - 1, tempValue = array[i];
            // 寻找待插入位置并移位
            while (j >= 0 && array[j] > tempValue) {
                array[j + 1] = array[j];
                j--;
            }
            // 此时 j + 1 就是要插入的位置（j + 1 = 0 或 tempValue >= array[j]）
            array[j + 1] = tempValue;   
        }
    }
}

int main() {
    vector<int> nums = {8, 4, 2, 9, 5, 7, 1, 3, 6};

    insertionSort(nums);

    printArray(nums);

    return 0;
}