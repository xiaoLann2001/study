#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // 自定义比较运算符
    class mycompare {
    public:
        bool operator()(const pair<int, int>& lhs, 
                        const pair<int, int>& rhs) {
            return lhs.second > rhs.second; // 小顶堆，从小到大
            // return lhs.second < rhs.second; // 大顶堆
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 用哈希映射统计频率<数字，频数>
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        // 定义优先级队列（小顶堆，大小为k）
        // 小顶堆的作用是在保持队列中元素个数为 k 的情况下，
        // 频率最低的元素会优先被移除。
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        mycompare> pri_que;

        // 用固定大小的小顶堆扫描map中所有元素
        for (unordered_map<int, int>::iterator it = freq.begin();
            it != freq.end(); it++) {
            pri_que.push(*it);
            // 堆的大小超过k时，弹出频率最小的元素
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        // 收集堆中剩下的元素，由于top频率小，数组从后面开始填充
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }

};

int main() {
    Solution s;

    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 5};
    int k = 3;

    vector<int> result = s.topKFrequent(nums, k);

    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
