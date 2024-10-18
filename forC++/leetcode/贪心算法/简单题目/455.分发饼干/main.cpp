#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 先对胃口和饼干排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 先满足胃口小的孩子
        int count = 0;  // 记录满足的孩子数，已分发的饼干数
        int next_cookie_idx = 0;    // 记录要满足下一个孩子需要的最小的饼干的位置
        for (int i = 0; i < g.size(); i++) {    // 按胃口从小到大遍历每一个孩子
            // 饼干从已经分发的下一个位置开始
            int j;
            for (j = next_cookie_idx; j < s.size(); j++) {  // 按尺寸从小到大遍历每一个饼干
                // 若胃口得到满足
                if (g[i] <= s[j]) {
                    count++;    // 记数加一
                    next_cookie_idx = j + 1;
                    break;
                }
            }
            // 若所有饼干都不能满足这个孩子了，那么后面的胃口更大的孩子也不行，直接返回
            if (j == s.size()) return count;
        }
        return count;
    }
};

// 优化，只遍历饼干一遍
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 先对胃口和饼干排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i, j;
        for (i = 0, j = 0; i < g.size() && j < s.size(); j++) {
            if (g[i] <= s[j]) i++;
        }
        return i;
    }
};

int main() {
    Solution s;

    vector<int> v_g = {1,2};
    vector<int> v_s = {1,2,3};

    int result = s.findContentChildren(v_g, v_s);

    cout << result << endl;

    return 0;
}