#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = -1, gas_accum = 0;
        // 初始化累计油量数组为两倍路径，以便处理环路
        vector<int> gas_cost_sub(gas.size() * 2);
        for (int i = 0; i < gas.size() * 2; i++) {
            gas_cost_sub[i] = gas[i % gas.size()] - cost[i % cost.size()];
        }
        for (int i = 0; i <= gas.size() + start; i++) {
            // 计算累计油量
            gas_accum += gas_cost_sub[i];
            // 若累计油量第一次大于0，记录起始点
            if (gas_accum >= 0 && start == -1) {
                start = i;
            }
            // 若累计油量小于0，清空油量重置起始点为-1
            else if (gas_accum < 0) {
                gas_accum = 0;
                start = -1;
            }
        }
        return start;
    }
};

int main() {
    Solution s;

    vector<int> gas = {0,0,0,1,1};
    vector<int> cost = {1,2,1,0,0};

    int result = s.canCompleteCircuit(gas, cost);

    cout << result << endl;

    return 0;
}