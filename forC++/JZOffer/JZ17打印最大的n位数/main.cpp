#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        // 先算出大小
        int size = pow(10, n) - 1;
        vector<int> result(size, 0);
        // 填值
        for (int i = 0; i < size; i++) result[i] = i + 1;
        return result;
    }
};

int main() {
    Solution s;

    int n = 2;

    vector<int> ret = s.printNumbers(n);

    for (const auto& n : ret) cout << n << " ";
    cout << endl;

    return 0;
}