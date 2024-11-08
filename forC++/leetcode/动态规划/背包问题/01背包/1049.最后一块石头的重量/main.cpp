// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        // 最难的是将问题转换为：选取石头让他们的重量之和最接近sum / 2，这样两堆石头碰撞后剩下的最小
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= 0; j--) {
                // if 写在循环条件里面也行，因为背包容量从大到小遍历，容量装不下当前物品时，前面的就更装不下了
                if (stones[i] <= j) dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]); 
            }
        }
        // dp[target]表示容量为target的背包最多装dp[target]重量的石头，
        // sum - dp[target]表示另一堆没有被选中的石头重量之和，因为target = sum / 2，
        // 所以target <= sum - target，剩下一堆重量一定大于等于dp[target]，相减后
        // 便是最后剩的石头重量
        return (sum - dp[target]) - dp[target];
    }
};

int main() {
    Solution s;

    vector<int> stones = {2,7,4,1,8,1};

    int result = s.lastStoneWeightII(stones);

    cout << result << endl;

    return 0;
}