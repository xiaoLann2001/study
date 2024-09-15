// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其总和大于等于 target 的长度最小的 连续
// 子数组
// [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 

// 示例 1：

// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 示例 2：

// 输入：target = 4, nums = [1,4,4]
// 输出：1
// 示例 3：

// 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
// 输出：0
 

// 提示：

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力解法，时间复杂度O(n^3)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for (int len = 1; len <= nums.size(); len++) {
            for (int idx = 0; idx < nums.size() - len + 1; idx++) {
                int sum = 0;
                for (int iidx = idx; iidx < idx + len; iidx++) {
                    sum += nums[iidx];
                }
                if (sum >= target) {
                    return len;
                }
            }
        }
        return 0;
    }
};

// 暴力解法O(n^2) from 代码随想录（遍历子数组的起始和结尾，j增加时加到sum即可，不用每次重新算）
// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int result = INT32_MAX; // 最终的结果
//         int sum = 0; // 子序列的数值之和
//         int subLength = 0; // 子序列的长度
//         for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
//             sum = 0;
//             for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
//                 sum += nums[j];
//                 if (sum >= s) { // 一旦发现子序列和超过了s，更新result
//                     subLength = j - i + 1; // 取子序列的长度
//                     result = result < subLength ? result : subLength;
//                     break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
//                 }
//             }
//         }
//         // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
//         return result == INT32_MAX ? 0 : result;
//     }
// };

// 双指针法（左右指针）（结果有错）
class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 0;
        int left = 0;
        int right = nums.size() - 1;
        // 因为子数组一定在数组之中，所以考虑用左右指针逼近，原则是 1.符合sum>=target要求 2.减小长度时保留尽量大的元素
        // 从最大的子数组开始遍历
        while (left <= right) {
            long long int sum = 0;
            for (int i = left; i <= right; i++) {
                sum += nums[i];
            }
            // 保留左右指针中更大的元素
            if (sum >= target) {
                // 更新子数组长度
                len = right - left + 1;
                if (nums[left] > nums[right])
                    right--;
                else
                    left++;
            }
            else {
                // 若最大的数组都不满足，直接返回初值0
                // 返回上一次满足条件的数组长度
                break;
            }
        }
        return len;
    }
};

// 双指针法（左右指针）（结果有误）（用做差改进，sum随双指针更新而更新）
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 0;
        int left = 0;
        int right = nums.size() - 1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 因为子数组一定在数组之中，所以考虑用左右指针逼近，原则是 1.符合sum>=target要求 2.减小长度时保留尽量大的元素
        // 从最大的子数组开始遍历
        while (left <= right) {
            // 做差防止溢出
            int dif = target - sum;
            
            // 保留左右指针中更大的元素
            if (dif <= 0) {
                // 更新子数组长度
                len = right - left + 1;
                if (nums[left] > nums[right]) {
                    dif += nums[right];
                    right--;
                }
                else {
                    dif += nums[left];
                    left++;
                }
            }
        }
        return len;
    }
};

// 双指针法（滑动窗口法）
class Solution3 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT32_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        for ( ; right < nums.size(); right++) {
            sum += nums[right];
            // if (sum >= target) {     // 不一定只前进一次
            while (sum >= target) {
                len = (right - left + 1) < len ? (right - left + 1) : len;
                sum -= nums[left++];
            }  
        }
        return (len == INT32_MAX) ? 0 : len;
    }
};

int main(){
    Solution3 s;

    int target = 697439;
    vector<int> nums = {5334,6299,4199,9663,8945,3566,9509,3124,6026,6250,7475,5420,9201,9501,38,5897,4411,6638,9845,161,9563,8854,3731,5564,5331,4294,3275,1972,1521,2377,3701,6462,6778,187,9778,758,550,7510,6225,8691,3666,4622,9722,8011,7247,575,5431,4777,4032,8682,5888,8047,3562,9462,6501,7855,505,4675,6973,493,1374,3227,1244,7364,2298,3244,8627,5102,6375,8653,1820,3857,7195,7830,4461,7821,5037,2918,4279,2791,1500,9858,6915,5156,970,1471,5296,1688,578,7266,4182,1430,4985,5730,7941,3880,607,8776,1348,2974,1094,6733,5177,4975,5421,8190,8255,9112,8651,2797,335,8677,3754,893,1818,8479,5875,1695,8295,7993,7037,8546,7906,4102,7279,1407,2462,4425,2148,2925,3903,5447,5893,3534,3663,8307,8679,8474,1202,3474,2961,1149,7451,4279,7875,5692,6186,8109,7763,7798,2250,2969,7974,9781,7741,4914,5446,1861,8914,2544,5683,8952,6745,4870,1848,7887,6448,7873,128,3281,794,1965,7036,8094,1211,9450,6981,4244,2418,8610,8681,2402,2904,7712,3252,5029,3004,5526,6965,8866,2764,600,631,9075,2631,3411,2737,2328,652,494,6556,9391,4517,8934,8892,4561,9331,1386,4636,9627,5435,9272,110,413,9706,5470,5008,1706,7045,9648,7505,6968,7509,3120,7869,6776,6434,7994,5441,288,492,1617,3274,7019,5575,6664,6056,7069,1996,9581,3103,9266,2554,7471,4251,4320,4749,649,2617,3018,4332,415,2243,1924,69,5902,3602,2925,6542,345,4657,9034,8977,6799,8397,1187,3678,4921,6518,851,6941,6920,259,4503,2637,7438,3893,5042,8552,6661,5043,9555,9095,4123,142,1446,8047,6234,1199,8848,5656,1910,3430,2843,8043,9156,7838,2332,9634,2410,2958,3431,4270,1420,4227,7712,6648,1607,1575,3741,1493,7770,3018,5398,6215,8601,6244,7551,2587,2254,3607,1147,5184,9173,8680,8610,1597,1763,7914,3441,7006,1318,7044,7267,8206,9684,4814,9748,4497,2239};

    int ret = s.minSubArrayLen(target, nums);

    cout << ret << endl;

    return 0;
}