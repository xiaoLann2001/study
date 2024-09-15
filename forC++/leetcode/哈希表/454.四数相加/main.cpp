// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，

// 数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

// 0 <= i, j, k, l < n

// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

#include <iostream>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1,
                     vector<int> &nums2,
                     vector<int> &nums3,
                     vector<int> &nums4)
    {
        // 需要统计每个和的频数,使用哈希映射
        // 将四个数组两两分组,以便查找,
        // 两个数组的和是一维,所以可以套用两数之和的思路
        unordered_map<int, int> sum12;
        
        // 将12数组的每种组合的和存入哈希映射
        for (int a : nums1) {
            for (int b : nums2) {
                sum12[a + b]++;
            }
        }

        // 依然使用 查找 (target-其中一个值) 的方法
        int target = 0; // 目标值
        int count = 0;  // 计数
        for (int c : nums3) {
            for (int d : nums4) {
                if (sum12[target - (c + d)]) {
                    // count++; // 这里要考虑到a+b的和有多种组合
                    count += sum12[target - (c + d)];
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {-1, -1};
    vector<int> n2 = {-1, 1};
    vector<int> n3 = {-1, 1};
    vector<int> n4 = {1, -1};

    int res = s.fourSumCount(n1, n2, n3, n4);

    cout << res << endl;

    return 0;
}