#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) return 0;
        // 确定dp数组及其下标含义
        int dp[cost.size() + 1];    // 到第i个楼梯，前面所要支付的最小费用
        // 初始化dp数组
        dp[0] = 0;
        dp[1] = 0;
        // 从前往后遍历
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        return dp[cost.size()];
    }
};

int main() {
    Solution s;

    vector<int> cost = {10, 15, 20};

    int result = s.minCostClimbingStairs(cost);

    cout << result << endl;

    return 0;
}