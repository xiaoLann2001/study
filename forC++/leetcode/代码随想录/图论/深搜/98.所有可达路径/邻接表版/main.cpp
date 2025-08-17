#include <bits/stdc++.h>

using namespace std;

// 邻接矩阵 vector<vector<int>>
// 邻接表 vector<list<int>>

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<list<int>> &graph, int s) {
        // 终止条件
        if (s == graph.size() - 1) {  // 若到达终点 n, 记录 path，并返回
            result.push_back(path);
            return;
        }
        // 单层递归逻辑
        // list<int>::iterator iter = graph[s].begin();
        // while (iter != graph[s].end()) {// 遍历当前节点指向的节点
        //     path.push_back(*iter);      // 处理节点
        //     backtracking(graph, *iter); // 递归当前节点指向的节点
        //     path.pop_back();            // 回溯
        //     iter++;
        // }
        for (int i : graph[s]) {// 找到 s 指向的节点
            path.push_back(i);  // 遍历到的节点加入到路径中来
            backtracking(graph, i);  // 进入下一层递归
            path.pop_back();    // 回溯，撤销本节点
        }
    } 

    vector<vector<int>> dfs(vector<list<int>> &graph) {
        result.clear();
        path.clear();
        path.push_back(1);
        backtracking(graph, 1);
        return result;
    }
};

int main() {
    // input and build graph
    int n, m, s, t;
    cin >> n >> m;
    vector<list<int>> graph(n + 1);    // 邻接表
    while (m--) {
        cin >> s >> t;
        graph[s].push_back(t);
    }

    // solve problem and output
    Solution sl;
    vector<vector<int>> result;
    result = sl.dfs(graph);
    if (result.empty()) cout << "-1" << endl;
    else {
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size() - 1; j++) cout << result[i][j] << " ";
            cout << result[i][result[i].size() - 1] << endl;
        }
    }

    return 0;
}