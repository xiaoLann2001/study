#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        int sizeof_array = numbers.size();
        if (0 == sizeof_array) {
            return -1;
        }

        // 数组统计数字出现频率
        vector<int> freq(sizeof_array, 0);

        for (int i = 0; i < sizeof_array; i++) {
            freq[numbers[i]]++;
            if (freq[numbers[i]] > 1) return numbers[i];
        }
        // 如果都不重复输出什么
        return -1;
    }
};

int main() {
    Solution s;

    vector<int> input = {2,3,1,0,2,5,3};

    int ret = s.duplicate(input);

    cout << ret << endl;

    return 0;
}