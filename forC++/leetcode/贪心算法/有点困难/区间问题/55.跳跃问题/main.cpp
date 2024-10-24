#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    bool backtracking(vector<int>& nums, int location) {
        if (location >= nums.size() - 1) return true;
        if (nums[location] == 0) return false;

        for (int i = nums[location]; i >= 1; i--) {
            if (backtracking(nums, location + i)) return true;
        } 
        return false;
    }

    bool canJump(vector<int>& nums) {
        return backtracking(nums, 0);
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            if (i + nums[i] > cover) cover = i + nums[i];
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main() {
    Solution s;

    vector<int> nums = {3,2,1,0,4};

    if (s.canJump(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }


    return 0;
}