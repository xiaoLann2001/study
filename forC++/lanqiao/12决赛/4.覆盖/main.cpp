#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> dp(5, vector<int>(5, 0));
    for (int i = 1; i < dp.size(); i++) {
        if (i % 2 == 0) dp[i][1] = 1;
    }
    for (int j = 1; j < dp[0].size(); j++) {
        if (j % 2 == 0) dp[1][j] = 1;
    }
    for (int i = 2; i < dp.size(); i++) {
        for (int j = 2; j < dp[0].size(); j++) {
            if ((i * j) % 2 == 1) dp[i][j] = 0;
            else {
                dp[i][j] = ;
            }
        }
    }

    for (auto v : dp) {
        for (auto n : v) cout << n << " ";
        cout << endl;
    }
    return 0;
}