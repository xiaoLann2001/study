#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int>& array) {
    for (const auto& n : array)
        cout << n << " ";
    cout << endl;
}

// 统计小数交换法
int partition1(vector<int>& array, int low, int high) {
    if (low == high) return low;
    
    // 随机选择一个元素作为枢轴元素（可选）
    // int randIndex = low + rand() % (high - low + 1);
    // swap(array[randIndex], array[high]);
    // 选择子数组末尾元素作为枢轴元素
    int pivot = array[high];

    // 统计比枢轴元素小的元素，并依次交换到左侧
    int smallerIndex = low;
    for (int i = low; i < high; i++) {
        if (array[i] < pivot) {
            swap(array[smallerIndex], array[i]);
            smallerIndex++;
        }
    }

    // 将枢轴元素换到正确的位置，此时枢轴元素左侧都是比它小的元素，右侧都是比它大的元素
    swap(array[smallerIndex], array[high]);

    return smallerIndex;
}

// 左右填坑法
int partition(vector<int>& array, int low, int high) {
    int pivot = array[low]; // pivot暂存枢轴元素
    while (low < high) {    // 不断挖坑直到low==high，两个while不能交换顺序，必须先填pivot挖的坑
        while (low < high && array[high] >= pivot) high--;
        array[low] = array[high];   // 从右往左，找到第一个小于枢轴的元素，填到左边的坑
        while (low < high && array[low] <= pivot) low++;
        array[high] = array[low];   // 从左往右，找到第一个大于枢轴的元素，填到右边的坑
    }
    array[low] = pivot;
    return low;
}

void quickSort(vector<int>& array, int left, int right) {
    if (left > right) return;
    int pivotIndex = partition(array, left, right);
    quickSort(array, left, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, right);
}

int main() {
    vector<int> nums = {8, 4, 2, 9, 5, 7, 1, 3, 6};

    printArray(nums);

    quickSort(nums, 0, nums.size() - 1);

    printArray(nums);

    return 0;
}