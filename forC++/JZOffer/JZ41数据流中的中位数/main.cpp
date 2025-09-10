#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void Insert(int num) {
        // if ((maxHeap.size() + minHeap.size()) & 1 == 0) {   // 总数为偶数，插入左边（注意运算优先级，== 会先运算）
        if (((maxHeap.size() + minHeap.size()) & 1) == 0) {   // 总数为偶数，插入左边
            if (!minHeap.empty() && num > minHeap.top()) {  // 待插入的数大于右边堆的最小值
                minHeap.push(num);      // 先插入到右边堆
                num = minHeap.top();    // 取出右边堆的最小值
                minHeap.pop();
            }
            maxHeap.push(num);          // 插入左边堆
        } else {    // 总数为奇数，插入右边
            if (!maxHeap.empty() && num < maxHeap.top()) {  // 待插入的数小于左边堆的最大值
                maxHeap.push(num);      // 先插入到左边堆
                num = maxHeap.top();    // 取出左边堆最大值
                maxHeap.pop();
            }
            minHeap.push(num);          // 插入右边堆
        }
    }

    double GetMedian() {
        if (maxHeap.size() + minHeap.size() == 0) { // 空
            return 0;
        } else if ((maxHeap.size() + minHeap.size()) & 1 == 1) {   // 奇数，中位数为左边堆最大值
            return maxHeap.top();
        } else {    // 偶数，平均值
            return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        }
    }

    priority_queue<int, vector<int>, less<int>> maxHeap;    // 大顶堆存左半部分
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆存右半部分
};

int main() {
    Solution s;

    vector<int> nums = {5,2,3,4,1,6,7,0,8};

    for (auto n : nums) {
        s.Insert(n);
        double ret = s.GetMedian();
        cout << fixed << setprecision(2) << ret << " ";
    }
    cout << endl;

    return 0;
}