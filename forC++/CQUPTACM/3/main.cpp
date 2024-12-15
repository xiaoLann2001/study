#include<bits/stdc++.h>

using namespace std;

long long count_hjm(vector<string> hjm) {
    vector<vector<long long>> dp(3, vector<long long>(hjm.size(), 0));
    // 初始化
    if (hjm[0] == "ha") {
        dp[0][0] = 1;
    }

    // 状态转移
    for (int i = 1; i < hjm.size(); i++) {
        if (hjm[i] == "ha") {
            dp[0][i] = dp[0][i - 1] + 1;
        } else {
            dp[0][i] = dp[0][i - 1];
        }
        if (hjm[i] == "ji") {
            dp[1][i] = dp[1][i - 1] + dp[0][i - 1];
        } else {
            dp[1][i] = dp[1][i - 1];
        }
        if (hjm[i] == "mi") {
            dp[2][i] = dp[2][i - 1] + dp[1][i - 1];
        } else {
            dp[2][i] = dp[2][i - 1];
        }
    }
    
    // 打印dp数组
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < hjm.size(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[2][hjm.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<string> hjm(n);
    for(int i = 0; i < n; i++)
    {
        cin >> hjm[i];
    }
    long long count = 0;
    count = count_hjm(hjm);
    cout << count << endl;

    return 0;
}