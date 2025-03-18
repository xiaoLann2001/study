#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int minNumberInRotateArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = -1;
        // 保证right一定属于第二个非降序区间，然后找最小的right
        while (left < right) {
            // mid = (left + right) / 2;   // 因为right一定属于第二个区间，为了寻找边界，优先将mid赋值偏左
            mid = left + (right - left) / 2;
            if (nums[left] < nums[right]) {
                return nums[left];
            } else if (nums[mid] > nums[left] || nums[mid] > nums[right]) {
                left = mid + 1; // mid属于第一个区间，则左半部分都为非递减，找右半部分
            } else if (nums[mid] < nums[left] || nums[mid] < nums[right]) {
                right = mid;    // mid属于第二个区间，说明最小值在左半部分，找左半部分（保证right始终属于第二个区间）
            } else {    // nums[left] == nums[mid] == nums[right]时，怎么办
                left++;
            }
        }
        return nums[right];
    }
};

int main() {
    Solution s;

    vector<int> input = {1, 2, 2, 2, 2};

    int ret = s.minNumberInRotateArray(input);

    cout << ret << endl;

    return 0;
}