#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 找到 <= target 的最大元素的位置
        if (nums.front() > target) return 0;
        if (nums.back() < target) return nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;     // 保证 left 位置始终满足条件
            } else {
                right = mid - 1;    // -1 防止死循环
            }
        }

        if (nums[left] != target) {
            left++;
        }
        return left;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int ret = s.searchInsert(nums, target);

    cout << ret << endl;

    return 0;
}