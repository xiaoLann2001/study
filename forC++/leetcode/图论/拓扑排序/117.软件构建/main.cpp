// #include <bits/stdc++.h>

// using namespace std;

// int n, m;
// vector<set<int>> dependency;    // 记录每个节点依赖的节点
// vector<bool> visited;           // 记录已访问（处理）元素

// int main() {
//     // 输入并初始化
//     int s, t;
//     cin >> n >> m;
//     dependency.resize(n);
//     visited.resize(n);
//     while (m--) {
//         cin >> s >> t;
//         dependency[t].insert(s);    // t 依赖于 s
//     }

//     // 模拟构建过程，需要处理 n 个文件
//     vector<int> result;
//     for (int i = 0; i < n; i++) {
//         // 一、选择不依赖其他文件的文件
//         int cur = -1;
//         for (int j = 0; j < n; j++) {
//             if (dependency[j].empty() && !visited[j]) { // 未处理且没有依赖的文件
//                 cur = j;
//                 break;
//             }  
//         }
//         if (cur == -1) break;   // 存在环形依赖

//         // 二、将当前节点加入已访问节点，记录结果
//         visited[cur] = true;
//         result.push_back(cur);

//         // 三、更新依赖关系，将已经访问的节点删除
//         for (int j = 0; j < n; j++) {
//             dependency[j].erase(cur); 
//         }
//     }

//     if (result.size() != n) {
//         cout << -1 << endl;
//     } else {
//         for (int i = 0; i < result.size() - 1; i++) cout << result[i] << " ";
//         cout << result[result.size() - 1] << endl;
//     }

//     return 0;
// }

// 拓扑排序，广度优先，入度数组
#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<int, vector<int>> umap;   // 记录依赖关系
vector<int> inDegree;   // 记录每个节点的入度

int main() {
    // 输入并初始化
    int s, t;
    cin >> n >> m;
    inDegree.resize(n);
    while (m--) {
        cin >> s >> t;
        umap[s].push_back(t);   // 记录依赖关系，s -> t
        inDegree[t]++;          // t 入度加一
    }

    // 先将入度为 0 的节点加入队列
    queue<int> que;         // 用于广度优先搜索的队列
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) que.push(i);
    }

    // 开始迭代处理
    vector<int> result;
    while (!que.empty()) {
        // 处理当前节点
        int cur = que.front();
        que.pop();
        result.push_back(cur);  // 记录结果
        // 更新依赖于当前节点的节点入度，并加入队列
        for (auto n : umap[cur]) {
            inDegree[n]--;  // n 入度减一
            if (inDegree[n] == 0) que.push(n);  
            // 会不会将之前遍历过的节点再次加入队列呢？
            // 不会，因为入度为零的节点不会在依赖列表中
        }
    }

    if (result.size() != n) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < result.size() - 1; i++) cout << result[i] << " ";
        cout << result[result.size() - 1] << endl;
    }

    return 0;
}