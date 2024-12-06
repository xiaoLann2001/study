#### （卡码网）47.参加科学大会

思路：
- 1.本题求最短路径，用广度优先搜索，搜索时迭代记录起点到每个节点的最短距离；
- 2.有以下推论成立：
    - 从**起点1**到**节点s**的最短距离 = min(从**起点1**到**与节点s相邻的节点**的最短距离 + **与节点s相邻的节点**到**节点s**的距离)；
- 3.动规五部曲（有动规的思想，但流程不大一样）：
    - 一、dp数组含义：`dp[i]`：从起点1到节点i的最短距离，跟prim算法中的minDist是一样的作用；
    - 二、递推公式：`dp[i] = min({dp[j] + distance[i][j], dp[k] + distance[i][k], ...})`，j，k...等节点为已访问集合中与i相邻的节点；
    - 三、dp数组初始化：`dp[1] = 0`，起点到自身的最短距离为0；
    - 四、遍历顺序：
        - i 的顺序不是简单的从 1 到 n，而是根据距离起点的最短距离得到的；
        - 节点i 本身是 与已访问集合相邻的距离起点最近的节点；
        - `dp[i]`由 已访问集合中的与i相邻的节点 得到，所以从起点开始，每次选择与已访问集合相邻的距离起点最近的节点 加入队列；
        - 像prim算法中的minDist数组一样，dp数组是在 已访问的集合中新加入一个节点时 更新与这个节点相邻的节点的 dp值；
    - 五、略；
- 4.算法流程：
    - 一、创建记录边权的表umap，记录已访问节点的数组visited，记录起点到某个节点的最短距离的数组dp；
    - 二、将 起点1 加入队列，初始化 dp[1] = 0；
    - 三、广度优先搜索：
        - 取出队首元素，加入已访问集合；
        - 更新与队首元素相邻（由队首元素指向的）的节点的 dp值；
        - 在未访问集合中 选择 距离起点最近的节点加入队列；
    - 四、若dp[n]为原始值INT32_MAX，输出-1，否则，输出dp[n]；

分析：
- 思路1 时间复杂度O(n^2)；

心得：
- 在分析已访问集合 和 未访问集合 之间的距离问题时，使用minDist数组是最合适的，原因如下：
    - 1.minDist数组每次**只需要更新** 与新加入节点相邻的节点所对应的 minDist值，减少重复计算；
    - 2.可以完成**所有**未访问节点 与 已访问集合的距离对比：
        - 如果集合内元素之间**没有相对距离**，如**prim算法**，则可求 与**整个已访问集合**的距离；
        - 如果集合内元素之间**有相对距离**，如**dijkstra算法**，则可求 与**集合中某个点**的距离；

反思：
- 不用队列更好，因为算法最关键的步骤有两步：
    - 1.**选择**距离起点最近的未访问节点；
    - 2.将当前节点**加入**已访问集合，并**更新**与它相邻的节点dp值（minDist值）；
- 使用队列只是将1.2.步骤颠倒：
    - 0.将起点放入队列；
    - 2.取出队首元素（一个），将当前节点**加入**已访问集合，**更新**节点dp值（minDist值）；
    - 1.**选择**节点放入队列（一个）；
- 这和循环n次，效果是一样的，但增加了队列入队出队的开销，由于每次只选择一个节点，而且选择的节点不是只依赖于当前节点，所以也不是严格意义上的广度优先搜索，下面还是给出两个版本的代码；

代码：
```c++
// 不标准的思路
#include <bits/stdc++.h>

using namespace std;

int n, m;
map<int, vector<pair<int, int>>> umap;  // 邻接表
vector<bool> visited;   // 已访问集合
vector<int> dp; // dp数组，表示minDist

int main() {
    // 输入并初始化
    int s, e, v;
    cin >> n >> m;
    visited.resize(n + 1, false);
    dp.resize(n + 1, INT32_MAX);
    dp[1] = 0;
    while (m--) {
        cin >> s >> e >> v;
        umap[s].push_back(pair<int, int>{e, v});
    }

    // 将起点加入队列
    queue<int> que;
    que.push(1);

    // 迭代求解
    while (!que.empty()) {
        // 队首节点：距离起点最近的未访问节点
        int cur = que.front();
        que.pop();
        // 将当前节点加入已访问集合，并更新与它相邻的节点dp值
        visited[cur] = true;
        for (pair<int, int> near : umap[cur]) {
            if (!visited[near.first]) dp[near.first] = min(dp[near.first], dp[cur] + near.second);
        }
        // 选择距离起点最近的未访问节点加入队列
        int next = -1;
        int minDist = INT32_MAX;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dp[i] < minDist) {
                next = i;
                minDist = dp[i];
            }
        }
        if (next != -1) que.push(next);
    }
    
    if (dp[n] == INT32_MAX) cout << -1 << endl;
    else cout << dp[n] << endl;

    return 0;
}
```

```c++
// 标准思路
#include <bits/stdc++.h>

using namespace std;

int n, m;
map<int, vector<pair<int, int>>> umap;  // 邻接表
vector<bool> visited;   // 已访问集合
vector<int> minDist;    // 节点距离起点的最短距离

int main() {
    // 输入并初始化
    int s, e, v;
    cin >> n >> m;
    minDist.resize(n + 1, INT32_MAX);
    visited.resize(n + 1, false);
    while (m--) {
        cin >> s >> e >> v;
        umap[s].push_back(pair<int, int>{e, v});
    }

    // 初始化
    minDist[1] = 0;

    // 迭代求解
    for (int i = 1; i < n; i++) {
        // 选择距离起点最近的未访问节点加入队列
        int cur = -1;
        int minTemp = INT32_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minDist[j] < minTemp) {
                cur = j;
                minTemp = minDist[j];
            }
        }
        // 将当前节点加入已访问集合，并更新与它相邻的节点dp值
        if (cur != -1) visited[cur] = true;
        for (pair<int, int> near : umap[cur]) {
            if (!visited[near.first]) minDist[near.first] = min(minDist[near.first], minDist[cur] + near.second);
        }
    }
    
    if (minDist[n] == INT32_MAX) cout << -1 << endl;
    else cout << minDist[n] << endl;

    return 0;
}
```