#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 一、暴力枚举 O(n*n)计算每个区间的面积并比较
        // 二、双指针按较大面积移动，因为只有边缘信息，所以需要移动至相遇
        // 三、双指针每次移动较小的那个（因为如果移动较大的那个，首先宽会减小，且min（h[left],h[right]）<= 之前的面积）
        // 四、所以移动高度较小的一个有可能找到最优解，移动较大的面积只会更小

        int left = 0, right = height.size() - 1;
        int maxArea = calculateArea(height, left, right);

        // 二
        // while (left < right) {
        //     int tempAreaLeftMove =  calculateArea(height, left + 1, right);
        //     int tempAreaRightMove =  calculateArea(height, left, right - 1);
        //     if (tempAreaLeftMove > tempAreaRightMove) {
        //         left++;
        //         maxArea = max(maxArea, tempAreaLeftMove);
        //     } else {
        //         right--;
        //         maxArea = max(maxArea, tempAreaRightMove);
        //     }
        // }

        // 三
        while (left < right) {
            if (height[left] < height[right]) {
                maxArea = max(maxArea, calculateArea(height, left++, right));
            } else {
                maxArea = max(maxArea, calculateArea(height, left, right--));
            }
        }

        return maxArea;
    }

    int calculateArea(vector<int>& height, int left, int right) {
        return (right - left) * min(height[left], height[right]);
    }
};

int main() {
    Solution s;

    // vector<int> in = {1,8,6,2,5,4,8,3,7};
    vector<int> in = {1,3,2,5,25,24,5};     // 按方法二错过了全局最优解

    int ret = s.maxArea(in);

    cout << ret << endl;

    return 0;
}