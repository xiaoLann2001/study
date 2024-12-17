#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> dp(2022, LONG_LONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= 2021; i++) {   // 设当前总节点数为 i
        for (int j = 0; j <= i - 1; j++) {  // 设左子树节点数为 j
            dp[i] = min(dp[i], 1 + 2 * dp[j] + 3 * dp[i - 1 - j] + j * j * (i - 1 - j));
        }
    }
    cout << dp[2021] << endl;
    return 0;
}