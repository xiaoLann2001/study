// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。

// 请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序 返回答案 。

#include <iostream>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // a + b + c + d = target
        // 四数之和，和15.三数之和 (opens new window)是一个思路，
        // 都是使用双指针法, 基本解法就是
        // 在15.三数之和 (opens new window)的基础上
        // 再套一层for循环。

        vector<vector<int>> result;

        int i, j, left, right;
        long sum;

        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size(); i++)
        {
            // 剪枝
            if ((nums[i] > target) &&
                (nums[i] >= 0))
                break;

            // a去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (j = i + 1; j < nums.size(); j++)
            {
                // 剪枝
                if ((nums[i] + nums[j] > target) &&
                    (nums[i] + nums[j] >= 0))
                    break;

                // b去重
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                left = j + 1;
                right = nums.size() - 1;

                while (left < right)
                {
                    // 把第一个加数强转为long，使得整个加法都是8字节的
                    sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        result.push_back(vector<int>{
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right],
                        });

                        // cd去重
                        while (left < right &&
                               nums[left] == nums[left + 1])
                            left++;
                        while (left < right &&
                               nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    int target = 1000000000;

    vector<vector<int>> res = s.fourSum(nums, target);

    for (vector<int> a : res)
    {
        for (int b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}