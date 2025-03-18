#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int Fibonacci(int n) {
        // Fib数组记录中间结果
        vector<int> Fib(41, 0);
        // 初始化
        Fib[1] = Fib[2] = 1;
        // 开始
        for (int i = 3; i <= n; i++) {
            Fib[i] = Fib[i - 1] + Fib[i - 2];
        }
        return Fib[n];
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int Fibonacci(int n) {
        vector<vector<int>> A = {{1, 1}, {1, 0}};
        vector<vector<int>> An_2 = fastPower(A, n - 2);
        return An_2[0][0] + An_2[0][1];
    }

    // 快速幂
    vector<vector<int>> fastPower(vector<vector<int>> base, unsigned int n) {
        vector<vector<int>> result = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) {
                result = matrix_multiply2(result, base);
            }
            base = matrix_multiply2(base, base);
            n = n >> 1;
        }
        return result;
    }

    // 2维矩阵乘法
    vector<vector<int>> matrix_multiply2(vector<vector<int>> A, vector<vector<int>> B) {
        vector<vector<int>> C(2, vector<int>(2, 0));
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        return C;
    }
};

int main() {
    Solution s;

    int n = 8;

    int ret = s.Fibonacci(n);

    cout << ret << endl;

    return 0;
}