#### （卡码网）97.小明逛公园

思路：
- 1.Floyd算法的核心思想是动态规划，本题需要求 **任意给定 起点start 和 终点end，求出最短路径**，为多源最短路径问题，那么需要频繁求取应该想到**建表查询**，故而想到动态规划可以将中间过程的结果保存；
- 2.动规五部曲：
    - 一、确定dp数组(grid数组)及其下标含义：
        - grid[i][j][k] = m，表示 节点i 到 节点j 以[1...k] 集合为中间节点的最短距离为m；
    - 二、确定递推公式：
        - grid[i][j][k]有两个来源：
            - i -> j 经过节点 k     ：**`grid[i][j][k] = grid[i][k][k - 1] + grid[k][j][k - 1]`**；
            - i -> j 不经过节点 k   ：**`grid[i][j][k] = grid[i][j][k - 1]`**；
        - 求最短路取最小值：
            - **`grid[i][j][k] = min(grid[i][k][k - 1] + grid[k][j][k - 1]， grid[i][j][k - 1])`**；
    - 三、初始化dp数组：
        - 首先将 i，j 两个维度组成的矩阵的对角线元素置 0，**`dp[i][i] = 0，1 <= i <= n`**，因为公园的道路长度大于等于 0，从自身出发到自身的最短距离为 0；
        - 然后在 k = 0 时（暂不讨论经过其他节点，先将图的原始信息记录下来）的 i，j 两个维度上填充图的邻接矩阵，未连接的节点填入道路长度最大值 + 1；
    - 四、确定遍历顺序：
        - 从递推公式：**`grid[i][j][k] = min(grid[i][k][k - 1] + grid[k][j][k - 1]， grid[i][j][k - 1])`** 可以看出，我们需要三个for循环，分别遍历i，j 和 k；
        - k 依赖于 k - 1， i 和j 的到 并不依赖与 i - 1 或者 j - 1 等等；
        - 讨论 经不经过 k 的结果，依赖于经不经过 k - 1 时的 grid[i][j]，所以 grid[i][j][k - 1] 必须全部更新完毕才能用于下一次求解，那么 k 必须放在最外层，而 i，j 的顺序不影响结果；
    - 五、举例推导：
        - ![Capture_20241210_165349.jpg](http://cdn.kamacoder.com/675816dca7c98-phpj8yThB.jpg) 
        - ![Capture_20241210_170106.jpg](http://cdn.kamacoder.com/675816efdbe5f-phpDHbHns.jpg) 
        - 这里可以看出：若要求 i -> j 经过 k 最短距离，需要知道 i -> k 和 k -> j 的最短距离，他们分别就是竖向的红框和横向的红框内的值；在红框内，有 i = k 或 j = k，此时 **i -> j 的最短距离** 等于 **i -> i 加上 i -> j** 或者 **i -> j 加上 j -> j**，也就是 i -> j 的最短距离，结果不变；所以**每一轮需要更新的dp值** 依赖于 **本轮不会变的dp值**，**不存在覆盖问题**，那么用**一个二维数组原地迭代更新**也就可行了； 
        - ![Capture_20241210_170122.jpg](http://cdn.kamacoder.com/675816f7bccc1-phph9YhQq.jpg) 
        - ![Capture_20241210_170134.jpg](http://cdn.kamacoder.com/675816ff4b512-phpeT4JxB.jpg) 
        - ![Capture_20241210_170150.jpg](http://cdn.kamacoder.com/67581705ae25e-phphrEfDp.jpg) 
        - 代码打印输出：
        - ![d9c44094-d80d-429c-b44f-85e7d10f5723.png](http://cdn.kamacoder.com/6758171e7f953-phpAAX4pD.png) 

分析：
- 如果路径有负数，那么从自身到自身的最短距离就不一定为 0 了，但也可以处理；
- 如果需要求最短路径的路由，也就是形成最短距离的节点，那么可以构造一个大小相同的二维数组 route（路由表），每次更新最短距离时，同步更新对应的 route 值为 k，表示 下一跳为k 能得到最短距离，按照路由表连续求出下一跳，直到下一跳为自身，便得到了路由；
    

代码：
```c++
// Floyd算法
#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<vector<vector<int>>> grid;

int main() {
    // 输入并初始化
    int u, v, w, start, end;
    cin >> n >> m;
    grid.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10001)));
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        grid[u][v][0] = w;  // 双向图
        grid[v][u][0] = w;
    }

    // grid数组对角线置0
    for (int i = 1; i <= n; i++) grid[i][i][0] = 0;

    // Floyd算法
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1]);
            }
        }
    }

    // 输出任意观景计划的结果
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        if (grid[start][end][n] != 10001) cout << grid[start][end][n] << endl;
        else cout << -1 << endl;
    }

    return 0;
}
```

```c++
// 优化空间的Floyd数组
#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<vector<int>> grid;

int main() {
    // 输入并初始化
    int u, v, w, start, end;
    cin >> n >> m;
    grid.resize(n + 1, vector<int>(n + 1, 10001));
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        grid[u][v] = w; // 双向图
        grid[v][u] = w;
    }

    // grid数组对角线置0
    for (int i = 1; i <= n; i++) grid[i][i] = 0;

    // Floyd算法
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }

    // // 输出grid数组
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 输出任意观景计划的结果
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        if (grid[start][end] != 10001) cout << grid[start][end] << endl;
        else cout << -1 << endl;
    }

    return 0;
}
```