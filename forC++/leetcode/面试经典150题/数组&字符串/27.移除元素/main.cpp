#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 不要求元素顺序可以用交换
        int i = 0;
        int k = nums.size();    // k表示目前不等于val的元素个数
        while (i < k) {
            if (nums[i] == val) {
                swap(nums[i], nums[k - 1]); // k-1的位置刚好是从末尾交换后第一个等于val的元素
                k--;
            } else {
                i++;
            }
        }
        return k;
    }
};

int main () {

    Solution s;

    vector<int> v1 = {3, 2, 2, 3};
    int val = 3;

    int k = s.removeElement(v1, val);

    for (int i = 0; i < k; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    return 0;
}