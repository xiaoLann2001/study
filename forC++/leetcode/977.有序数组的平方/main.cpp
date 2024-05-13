#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力解法，先平方再排序，或者绝对值排序后再平方，没有利用数组的有序性
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size());

        transform(nums.begin(), nums.end(), v.begin(), [](int val) { return val * val; });

        sort(v.begin(), v.end());

        return v;
    }
};

// 双指针法
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        // 因为平方后的最大值只可能在左边或右边
        int left = 0;                   // 左指针
        int right = nums.size() - 1;    // 右指针
        int idx = nums.size() - 1;      // 记录新的数组的最大值索引
        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                result[idx] = nums[left] * nums[left];
                ++left;
                --idx;
            }
            else {
                result[idx] = nums[right] * nums[right];
                --right;
                --idx;
            }
        }

        return result;
    }
};

int main(){
    Solution1 s;

    vector<int> nums = {-4,-1,0,3,10};

    vector<int> v = s.sortedSquares(nums);

    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
    cout << endl;

    return 0;
}