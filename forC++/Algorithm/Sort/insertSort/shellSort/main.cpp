#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int>& array) {
    for (const auto& n : array)
        cout << n << " ";
    cout << endl;
}

// shell排序是插排的改进版，利用了插排两个优点：1. 数据量少时效率高 2. 数据相对有序时效率高
// shell排序的分组策略使得每组元素数据量减少，提高插排效率；
// 在间距减小后，由于前面的操作，数组已经一定程度有序，也一定程度提高插排效率。
void shellSort(vector<int>& array) {
    int n = array.size();
    for (int d = n / 2; d >= 1; d /= 2) {   // 间隔d的数分为一组，进行插排，总共d组，然后缩小间隔，执行同样操作
        for (int i = d; i < n; i++) {       // 插入排序（间隔d版）
            if (array[i] < array[i - d]) {
                int j = i - d, tempValue = array[i];
                // 寻找待插入位置并移位
                while (j >= 0 && array[j] > tempValue) {
                    array[j + d] = array[j];
                    j -= d;
                }
                // 此时 j + d 就是要插入的位置（j + d = 0 或 tempValue >= array[j]）
                array[j + d] = tempValue;   
            }
        }
    }
}

int main() {
    vector<int> nums = {8, 4, 2, 9, 5, 7, 1, 3, 6};

    printArray(nums);

    shellSort(nums);

    printArray(nums);

    return 0;
}