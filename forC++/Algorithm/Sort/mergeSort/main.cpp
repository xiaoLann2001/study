#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int>& array) {
    for (const auto& n : array)
        cout << n << " ";
    cout << endl;
}

void merge(vector<int>& array, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    vector<int> tempArray(array.size());

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            tempArray[k++] = array[i++];
        else
            tempArray[k++] = array[j++];
    }

    while (i <= mid)
        tempArray[k++] = array[i++];
    
    while (j <= right)
        tempArray[k++] = array[j++];

    for (int idx = left; idx <= right; idx++)
        array[idx] = tempArray[idx];
}

// 归并排序非递归版
void mergeSort(vector<int>& array) {
    int n = array.size();
    for (int seg = 1; seg < n; seg *= 2) {
        for (int left = 0; left < n - seg; left += seg * 2) {
            int mid = left + seg - 1;
            int right = min(left + seg * 2 - 1, n - 1);
            merge(array, left, mid, right);
        }
    }
}

// 归并排序递归版
void mergeSortRecursion(vector<int>& array, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortRecursion(array, left, mid);
    mergeSortRecursion(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main() {
    vector<int> nums = {8, 4, 2, 9, 5, 7, 1, 3, 6};

    printArray(nums);

    // mergeSort(nums);
    mergeSortRecursion(nums, 0, nums.size() -1);

    printArray(nums);

    return 0;
}