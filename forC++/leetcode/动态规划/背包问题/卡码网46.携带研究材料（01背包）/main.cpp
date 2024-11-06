// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

// 二维dp数组
class Solution1 {
public:
    int bag(int capacity, vector<int> weight, vector<int> value) {
        // 确定dp数组及其下标含义
        vector<vector<int>> dp(weight.size(), vector<int>(capacity + 1, 0));

        // 初始化dp数组，第一列在前面已经初始化为0了
        for (int j = 0; j <= capacity; j++) {
            dp[0][j] = weight[0] > j ? 0 : value[0];
        }

        // 遍历dp数组
        for (int i = 1; i < weight.size(); i++) {
            for (int j = 1; j <= capacity; j++) {
                if (weight[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }

        // // 打印dp数组
        // cout << "dp array: " << endl;
        // for (auto v : dp) {
        //     for (auto n : v) {
        //         cout << n << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        return dp[weight.size() - 1][capacity];
    }
};

// 滚动数组
class Solution {
public:
    int bag(int capacity, vector<int> weight, vector<int> value) {
        // 确定dp数组及其下标含义，及初始化
        vector<int> dp(capacity + 1, 0);

        // 打印dp数组
        // cout << "dp array: " << endl;
        // for (auto n : dp) {
        //     cout << n << " ";
        // }
        // cout << endl;

        // 遍历dp数组
        for (int i = 0; i < weight.size(); i++) {

            for (int j = capacity; j >= 0; j--) {   // 倒序遍历背包容量
                if (weight[i] > j) {
                    dp[j] = dp[j];
                }
                else {
                    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
            }

            // for (auto n : dp) {
            //     cout << n << " ";
            // }
            // cout << endl;
        }

        return dp[capacity];
    }
};

int main() {
    Solution s;

    int n, capacity;
    cin >> n >> capacity;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    int result = s.bag(capacity, weight, value);

    cout << result << endl;

    return 0;
}