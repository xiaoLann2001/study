#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int count = 0;
        for (int i = 0; i < nums.size();) {
            // 若范围未到最后一个元素，选择范围内能使范围更大的元素跳跃
            int next = i;   // 记录下一跳位置
            if (i + nums[i] < nums.size() - 1) {
                int cover_temp = i + nums[i];
                for (int j = i; j <= i + nums[i]; j++) {
                    if (j + nums[j] > cover_temp) {  // 选择使范围更大的元素
                        cover_temp = j + nums[j];    // 更新最大范围
                        next = j;
                    }
                }
                i = next;   // 跳到next的位置
                count++;    // 跳跃次数加一
            } else {    // 若已能跳到最后一个元素
                count++;
                break;
            }
        }
        return count;
    }
};

int main() {
    Solution s;

    vector<int> nums = {2,3,1,1,4};

    cout << s.jump(nums) << endl;

    return 0;
}