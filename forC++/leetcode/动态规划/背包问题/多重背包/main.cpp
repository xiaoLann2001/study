// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

// 滚动数组
class Solution1 {
public:
    int bag(int c, int n, vector<int> warray, vector<int> varray, vector<int> karray) {
        vector<int> dp(c + 1, 0);

        int nums = accumulate(karray.begin(), karray.end(), 0);
        // cout << nums << endl;
        warray.resize(nums);        
        varray.resize(nums);
        int p = n;
        for (int i = 0; i < n; i++) {
            while (karray[i] > 1) { // 物品数量不是一的，都展开
                warray[p] = warray[i];
                varray[p] = varray[i];
                karray[i]--;
                p++;
            }
        }
        
        for (int i = 0; i < warray.size(); i++) {
            for (int j = c; j >= warray[i]; j--) {
                dp[j] = max(dp[j], dp[j - warray[i]] + varray[i]);
            }

            // for (auto n : dp) cout << n << " ";
            // cout << endl;
        }
        return dp[c];
    }
};

// 滚动数组
class Solution {
public:
    int bag(int c, int n, vector<int> warray, vector<int> varray, vector<int> karray) {
        vector<int> dp(c + 1, 0);
        
        for(int i = 0; i < n; i++) { // 遍历物品
            for(int j = c; j >= warray[i]; j--) { // 遍历背包容量
                // 以上为01背包，然后加一个遍历个数
                for (int k = 1; k <= karray[i] && (j - k * warray[i]) >= 0; k++) { // 遍历个数
                    dp[j] = max(dp[j], dp[j - k * warray[i]] + k * varray[i]);
                }
            }
        }
        return dp[c];
    }
};

int main() {
    Solution s;

    int c, n;
    cin >> c >> n;

    vector<int> w(n), v(n), k(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    int result = s.bag(c, n, w, v, k);

    cout << result << endl;

    return 0;
}