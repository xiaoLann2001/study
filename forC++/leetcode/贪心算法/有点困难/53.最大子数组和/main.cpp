#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        // 双指针记录子区间的局部和
        int max = INT32_MIN, local_sum = 0, left = 0, right = 0;
        for (right = 0; right < nums.size(); right++) {
            local_sum += nums[right];
            if (local_sum > max) {
                max = local_sum;
            }
            if (local_sum < 0) {
                local_sum = 0;
                left = right + 1;
            }
        }
        printf("left: %d right: %d\n", left, right);
        return max;
    }
};

int main() {
    Solution s;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int result = s.maxSubArray(nums);

    cout << result << endl;

    return 0;
}