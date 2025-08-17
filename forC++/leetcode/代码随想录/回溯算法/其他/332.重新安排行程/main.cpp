#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> airports;
    unordered_map<string, int> airport_order_map;
    vector<vector<int>> tickets_table;
    vector<string> path;

    static bool dirc_order_compare(string first, string second) {
        int idx = 0;
        while (idx < 3) {
            if (first[idx] < second[idx]) return true;
            if (first[idx] > second[idx]) return false;
            idx++;
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 预处理，将机票信息转换为矩阵信息
        for (vector<string> t : tickets) {
            // 若机场是第一次出现，加入机场数组
            if (find(airports.begin(), airports.end(), t[0]) == airports.end()) {
                airports.push_back(t[0]);
            }
            if (find(airports.begin(), airports.end(), t[1]) == airports.end()) {
                airports.push_back(t[1]);
            }
        }
        // 对机场名称排序
        sort(airports.begin(), airports.end(), dirc_order_compare);
        // 将排序后的机场名称及其索引存入哈希映射
        for (int i = 0; i < airports.size(); i++) {
            airport_order_map.insert(pair<string, int>(airports[i], i));
        }
        // 再次遍历机票数组，将机票信息转换为二维数组
        tickets_table.resize(airports.size(), vector<int>(airports.size(), 0));
        for (vector<string> t : tickets) {
            tickets_table[airport_order_map[t[0]]][airport_order_map[t[1]]]++;
        }
        // 预处理结束

        path.clear();
        backtracking(airport_order_map["JFK"], tickets.size());
        return path;
    }

    bool backtracking(int start_airport_order, int tickets_num) {
        // 出发机场先入栈
        path.push_back(airports[start_airport_order]);
        // 若没有机票了，快速返回
        if (tickets_num == 0) {
            return true;
        }
        // 遍历机场，查看是否有到其他机场的机票
        for (int i = 0; i < airports.size(); i++) {
            if (tickets_table[start_airport_order][i] > 0) {
                tickets_table[start_airport_order][i]--;    // 用掉这张票
                if (backtracking(i, tickets_num - 1)) {     // 进入下一个机场
                    return true;    // 快速返回
                }           
                tickets_table[start_airport_order][i]++;    // 撤销处理
            }
        }
        // 没有可行路，返回上一个机场
        path.pop_back();
        return false;
    }
};

int main() {
    Solution s;

    vector<vector<string>> tickets = {
        {"EZE", "AXA"},
        {"TIA", "ANU"},
        {"ANU", "JFK"},
        {"JFK", "ANU"},
        {"ANU", "EZE"},
        {"TIA", "ANU"},
        {"AXA", "TIA"},
        {"TIA", "JFK"},
        {"ANU", "TIA"},
        {"JFK", "TIA"}
    };

    vector<string> result = s.findItinerary(tickets);

    for (string str : result) {
        cout << str << endl;
    }

    return 0;
}