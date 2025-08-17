#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue mq;
        vector<int> result;

        for (int i = 0; i < k; i++) {
            mq.push(nums[i]);
        }
        result.push_back(mq.getFront());

        for (int i = k; i < nums.size(); i++) {
            mq.pop(nums[i - k]);
            mq.push(nums[i]);
            result.push_back(mq.getFront());
        }

        return result;
    }
private:
    class MyQueue   // 单调队列，从大到小
    {
    private:
        deque<int> q;   // 双向队列
    public:
        // 当要弹出的元素等于队首（当前窗口最大值）时，才弹出
        // 若要弹出的元素不等于队首，说明不是当前窗口最大值，在之前
        // 其他元素push时就被弹出了
        void pop(int value) {
            if (!q.empty() && value == q.front()) {
                q.pop_front();
            }
        }

        // 若要压入元素大于队尾，不满足单调递减，则弹出队尾，
        // 直到压入元素小于队尾，然后压入新的元素
        void push(int value) {
            while (!q.empty() && value > q.back()) {
                q.pop_back();
            }
            q.push_back(value);
        }

        // 由于满足单调递减且队列中元素都在当前窗口，
        // 所以队首元素就是当前窗口最大值
        int getFront() {
            return q.front();
        }
    };
};

int main() {
    Solution s;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> result;
    int k = 3;

    result = s.maxSlidingWindow(nums, k);

    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
