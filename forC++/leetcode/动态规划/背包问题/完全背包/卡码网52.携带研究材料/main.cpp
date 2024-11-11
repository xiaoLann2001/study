// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

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
            for (int j = weight[i]; j <= capacity; j++) {   // 正序遍历背包容量
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }

            for (auto n : dp) {
                cout << n << " ";
            }
            cout << endl;
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
        cin >> weight[i] >> value[i];
    }

    int result = s.bag(capacity, weight, value);

    cout << result << endl;

    return 0;
}