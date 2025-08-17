#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    static bool mycompare(int first, int second) {
        if (abs(first) > abs(second)) return true;
        return false;
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), mycompare);
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (i == nums.size() - 1) {
                while (k--) nums[i] = -nums[i];
                break;
            }
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            } else if (nums[i] > 0) {
                continue;
            } else {    // nums[i] == 0时，到达末尾，对零翻转直到次数用完，和不变
                break;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main() {
    Solution s;

    vector<int> nums = {2,-3,-1,5,-4};
    int k = 2;

    cout << s.largestSumAfterKNegations(nums, k) << endl;

    return 0;
}