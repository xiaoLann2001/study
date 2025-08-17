#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
                result = max(result, count);
            } else {
                count = 1;
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,3,5,4,7};

    int result;
    result = s.findLengthOfLCIS(nums);

    cout << result << endl;

    return 0;
}