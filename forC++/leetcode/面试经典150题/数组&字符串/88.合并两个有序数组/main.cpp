#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }

        if (m == 0) {
            for (int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }
        
        // 从num1的尾部开始插入两个数组中的最大值，保证num1原来的值不被覆盖
        int p_insert = m + n - 1;    // 待插入位置
        int p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p_insert--] = nums1[p1--];
            } else {
                nums1[p_insert--] = nums2[p2--];
            }
        }

        while (p1 >= 0) {
            nums1[p_insert--] = nums1[p1--];
        }

        while (p2 >= 0) {
            nums1[p_insert--] = nums2[p2--];
        }
    }
};

int main () {

    Solution s;

    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};

    s.merge(v1, v1.size() - v2.size(), v2, v2.size());

    for (int n : v1) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}