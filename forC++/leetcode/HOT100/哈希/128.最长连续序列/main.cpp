#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 思路一：
        // 用一个数组v1记录有哪些数字已出现（也可换成哈希表）
        // 用一个数组v2表示当前数字所在的连续数组的长度（也可换成哈希表）
        // 1. 当数字两侧没有元素时，v2[i] = 1
        // 2. 当数字左侧或者右侧有元素时，v2[i] = 1 + v2[i+-1]，相邻所有元素也更新
        // 3. 当数字两侧都有元素时，v2[i] = 1 + v2[i-1] + v2[i+1]，相邻所有元素也更新
        // 最差的情况更新 n(n + 1) / 2 次

        // 思路二：
        // 由于区间的合并只在边界发生
        // 在思路一的基础上只更新边界值，边界位置可根据边界值快速找到
        // 1. 当数字两侧没有元素时，v2[i] = 1
        // 2. 当数字左侧有元素（为右边界）时，v2[i] = 1 + v2[i-1]，v2[i-v2[i-1]] = v2[i]
        // 3. 当数字右侧有元素（为左边界）时，v2[i] = 1 + v2[i+1]，v2[i+v2[i+1]] = v2[i]
        // 4. 当数字两侧都有元素（左侧为右边界，右侧为左边界）时，v2[i] = 1 + v2[i-1] + v2[i+1]，v2[i-v2[i-1]] = v2[i], v2[i+v2[i+1]] = v2[i]
        // 需要标记边界，或者更新边界

        // unordered_map<int, pair<int, int>> umap;    // pair.second标记边界：0不是边界，1左边界，2右边界z，3同时是左右边界
        // int result = 0;

        // for (const int& n : nums) {
        //     int total = 0;
        //     // 左右都不是边界
        //     if (umap[n - 1].second == 0 && umap[n + 1].second == 0) {
        //         // 同时为左右边界
        //         total = 1;
        //         umap[n].first = total;
        //         umap[n].second = 3;
        //     } 
        //     // 右侧是左边界，左侧不是边界
        //     else if (umap[n - 1].second == 0 && (umap[n + 1].second & 1) == 1) {
        //         // 新建左边界
        //         total = 1 + umap[n + 1].first;
        //         umap[n].first = total;
        //         umap[n].second = 1;
        //         // 更新原来的右边界
        //         umap[n + umap[n + 1].first].first = total;
        //         // 消除原来的左边界
        //         if (umap[n + 1].second == 1) {  // 只是左边界
        //             umap[n + 1].first = 0;
        //             umap[n + 1].second = 0;
        //         } else {    // 同时为右边界
        //             umap[n + 1].second = 2;
        //         }
        //     } 
        //     // 左侧是右边界，右侧不是边界
        //     else if ((umap[n - 1].second & 2) == 2 && umap[n + 1].second == 0) {
        //         // 新建右边界
        //         total = 1 + umap[n - 1].first;
        //         umap[n].first = total;
        //         umap[n].second = 2;
        //         // 更新原来的左边界
        //         umap[n - umap[n - 1].first].first = total;
        //         // 消除原来的右边界
        //         if (umap[n - 1].second == 2) {  // 只是右边界
        //             umap[n - 1].first = 0;
        //             umap[n - 1].second = 0;
        //         } else {    // 同时为左边界
        //             umap[n - 1].second = 1;
        //         }
        //     }
        //     // 左侧是右边界且右侧是左边界
        //     else if ((umap[n - 1].second & 2) == 2 && (umap[n + 1].second & 1) == 1) {
        //         total = 1 + umap[n - 1].first + umap[n + 1].first;
        //         // 更新最外侧的边界
        //         umap[n - umap[n - 1].first].first = total;
        //         umap[n + umap[n + 1].first].first = total;
        //         // 消除原来内侧的边界
        //         // 消除原来的右边界
        //         if (umap[n - 1].second == 2) {  // 只是右边界
        //             umap[n - 1].first = 0;
        //             umap[n - 1].second = 0;
        //         } else {    // 同时为左边界
        //             umap[n - 1].second = 1;
        //         }
        //         // 消除原来的左边界
        //         if (umap[n + 1].second == 1) {  // 只是左边界
        //             umap[n + 1].first = 0;
        //             umap[n + 1].second = 0;
        //         } else {    // 同时为右边界
        //             umap[n + 1].second = 2;
        //         }
        //     }
        //     // 左侧是左边界或者右侧是右边界
        //     else if (umap[n - 1].second == 1 || umap[n + 1].second == 2) {
        //         // do nothing
        //     } else {
        //         // 按理说没有这种情况
        //         result = INT32_MAX;
        //     }

        //     result = max(result, total);
        // }

        // return result;

        // 思路三：
    if (1) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;

        for (int n : num_set) {
            if (!num_set.count(n - 1)) { // 只有是序列起点才进入（序列起点前没有元素）
                int current = n;
                int length = 1;

                while (num_set.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
    }
};

int main() {
    Solution s;

    vector<int> in = {-7,-1,3,-9,-4,7,-3,2,4,9,4,-9,8,-7,5,-1,-7};

    int ret = s.longestConsecutive(in);

    cout << ret << endl;

    return 0;
}