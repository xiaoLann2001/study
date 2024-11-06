#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = 1;
        // dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = 1;
        // dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i / 2; j++) {
                dp[i] += 2 * dp[j - 1] * dp[i - j];
            }
            dp[i] += (i % 2) * dp[i / 2] * dp[i / 2];
        }
        return dp[n];
    }
};

int main() {
    Solution s;

    int n = 3;

    int result = s.numTrees(n);

    cout << result << endl;

    return 0;
}