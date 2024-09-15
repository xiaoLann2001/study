// 编写一个算法来判断一个数 n 是不是快乐数。

// 「快乐数」 定义为：

// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

#include <iostream>
#include <vector>
#include <algorithm>

#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums;
        unordered_set<int> sums;
        
        // 重复,直到和为1
        while (1 != n) {
            // 将n按位拆分,存入数组
            while (n) {
                nums.push_back(n % 10);
                n /= 10;
            }

            // 求每一位平方的和
            while (!nums.empty()) {
                n += (nums.back() * nums.back());
                nums.pop_back();
            }

            // 若不是快乐数,该怎么返回false
            // 不是快乐数会无限循环,表明求和结果会重复
            // 用哈希表记录求和结果,若重复出现则返会false
            if (sums.count(n)) {
                return false;
            }
            sums.insert(n);
        }

        // 结束循环,是快乐数
        return true;
    }
};

class Solution1 {
public:
    bool isHappy(int n) {
        int sum;
        unordered_set<int> sums;
        
        // 重复,直到和为1
        while (1 != n) {
            // 改进1: 简化求和算法
            sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;

            // 若不是快乐数,该怎么返回false
            // 不是快乐数会无限循环,表明求和结果会重复
            // 用哈希表记录求和结果,若重复出现则返会false
            if (sums.count(sum)) {
                return false;
            }
            sums.insert(sum);
        }

        // 结束循环,是快乐数
        return true;
    }
};

int main()
{
    Solution1 s;
    int n = 2;

    if (s.isHappy(n)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}