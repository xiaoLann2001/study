// 给你一个整数数组 nums ，

// 判断是否存在三元组 [nums[i], nums[j], nums[k]]

// 满足 i != j、i != k 且 j != k ，

// 同时还满足 nums[i] + nums[j] + nums[k] == 0 。

// 请你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

#include <iostream>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        // 双指针法
        int i, left, right;

        // 先对数组排序
        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size() - 1; i++) {
            // 排序之后如果第一个元素已经大于零，
            // 那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) 
                return result;
            
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            left = i + 1;
            right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i],
                                                nums[left],
                                                nums[right]});
                    // break;  // 这里break掉会跳过进一步的三元组查找

                    // 对bc去重,重复的三元组一定在找到的之后
                    // 满足和的条件但不统计
                    while (left < right && 
                           nums[left] == nums[left + 1]) 
                            left++;
                    while (left < right && 
                           nums[right] == nums[right - 1]) 
                            right--;
                    
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = s.threeSum(nums);

    for (vector<int> a : res) {
        for (int b : a) {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}