#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int preDiff = 0;    // 默认preDiff = 0，相当于为第一个元素延长出一个平坡
        int curDiff = 0;
        int count = 1;  // 默认最后一个元素有一个摆动
        for (int i = 0; i < nums.size() - 1; i++) { // 不遍历最后一个元素，只有一个元素时直接返回count=1 
            curDiff = nums[i + 1] - nums[i];
            // 只记录峰值且考虑上下坡有平坡
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                count++;
                preDiff = curDiff;  // 只在摆动出现后，记录preDiff初始坡度
            }
            // preDiff = curDiff;  // 记录preDiff，单调坡中有平坡时会出错
        }
        return count;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,17,5,8,8,10,13,15,10,5,16,8};

    int result = s.wiggleMaxLength(nums);

    cout << result << endl;

    return 0;
}