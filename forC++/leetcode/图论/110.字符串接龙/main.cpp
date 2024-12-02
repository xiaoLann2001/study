#include <bits/stdc++.h>

using namespace std;

int n;
string beginStr, endStr;
vector<string> strList;
vector<vector<int>> g;
vector<int> visited;

// 比较两个字符串是否只有一个字符不同
int str_compare_gap_one(string s1, string s2) {
    if (s1.size() == 0 || s2.size() == 0 || s1.size() != s2.size()) return false;
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) count++;
    }
    return count == 1 ? 1 : 0;
}

int main() {
    // 输入并初始化
    cin >> n;
    g.resize(n + 2, vector<int>(n + 2, 0));
    strList.resize(n + 2);
    visited.resize(n + 2);
    cin >> beginStr >> endStr;
    while (n--) {
        cin >> strList[n + 1];
    }

    // 两两比较字符串，将转换关系抽象到图中，端用序号表示字符串
    strList[0] = beginStr;
    strList[strList.size() - 1] = endStr;
    for (int i = 0; i < strList.size(); i++) {
        for (int j = 0; j < strList.size(); j++) {
            if (i == j) continue;   // 也可以不要，字符串自身不能转换
            g[i][j] = str_compare_gap_one(strList[i], strList[j]);
        }
    } 

    // 用广搜求最短路径长度
    int path_length = 0;
    queue<int> queue_next;
    queue_next.push(-1);    // 每加入一层节点，做好层数标记
    queue_next.push(0);     // 压入 beginStr 对应序号
    visited[0] = 1;         // 标记已访问
    while (!queue_next.empty()) {
        // 检查层数标记，检查是否开始处理新一层节点
        if (queue_next.front() == -1) {
            queue_next.pop();
            queue_next.push(-1);    // 压入层数标记，以区分待加入的更新的一层的节点
            path_length++;          // 记录广搜层数，即路径上节点数量
        }
        // 当前节点
        int i = queue_next.front();
        queue_next.pop();
        if (i == strList.size() - 1) break; // 找到终点，退出遍历
        // 相邻节点
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] == 1 && visited[j] == 0) {
                queue_next.push(j);
                visited[j] = 1; // 标记已访问
            } 
        }
    }

    cout << path_length << endl;

    return 0;
}