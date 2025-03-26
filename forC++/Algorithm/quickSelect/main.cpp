#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& array) {
    for (const auto& n : array)
        cout << n << " ";
    cout << endl;
}

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[high]);
    return i;
}

// 可以选择数组中第 k 大的元素
int quickselect(vector<int>& nums, int low, int high, int k) {
    if (low == high) return nums[low];

    int pivotIndex = partition(nums, low, high);

    if (k == pivotIndex)
        return nums[k];
    else if (k < pivotIndex)
        return quickselect(nums, low, pivotIndex - 1, k);
    else
        return quickselect(nums, pivotIndex + 1, high, k);
}

double findMedian(vector<int>& nums) {
    int n = nums.size();
    if (n & 1) {
        int mid = n / 2;
        return quickselect(nums, 0, n - 1, mid);
    } else {
        int midl = n / 2;
        int midr = n / 2 + 1;
        double medianl = quickselect(nums, 0, n - 1, midl);
        double medianr = quickselect(nums, 0, n - 1, midr);
        return (medianl + medianr) / 2.0;
    }
}

int main() {
    vector<int> nums = {7, 3, 5, 1, 9, 6, 8, 6};
    
    printArray(nums);
    
    cout << "中位数是: " << findMedian(nums) << endl;
    
    return 0;
}
