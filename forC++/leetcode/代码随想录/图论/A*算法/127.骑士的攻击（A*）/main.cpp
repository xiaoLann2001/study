// #include <bits/stdc++.h>

// using namespace std;

// #define MIN_X 1
// #define MIN_Y 1
// #define MAX_X 1000
// #define MAX_Y 1000

// #define Euler
// // #define Manhattan
// // #define Chebyshev

// const vector<vector<int>> dir = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
//                                  {-2, -1}, {-1, -2}, {1, -2}, {2, -1}}; // 骑士规则

// int n;
// int x_start, y_start, x_end, y_end;

// // 是否在合理范围
// bool isInBox(int x, int y) {
//     return x >= MIN_X && y >= MIN_Y && x <= MAX_X && y <= MAX_Y;
// }

// // 欧拉距离的平方
// int distance_Euler_squre(int x1, int y1, int x2, int y2) {
//     return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);   // 不开平方，只需比较大小
// }

// // 曼哈顿距离
// int distance_Manhattan(int x1, int y1, int x2, int y2) {
//     return abs(x1 - x2) + abs(y1 - y2);
// }

// // 切比雪夫距离
// int distance_Chebyshev(int x1, int y1, int x2, int y2) {
//     return max(abs(x1 - x2), abs(y1 - y2));
// }

// // 启发函数，当前节点距离起点和终点的距离和 F = G + H
// // G = 从起点到该节点路径消耗
// // H = 该节点到终点的预估消耗
// int Heuristic(int x, int y) {
// #ifdef Euler
//     return distance_Euler_squre(x, y, x_start, y_start) +
//            distance_Euler_squre(x, y, x_end, y_end);
// #endif
// #ifdef Manhattan
//     return distance_Manhattan(x, y, x_start, y_start) +
//            distance_Manhattan(x, y, x_end, y_end);
// #endif
// #ifdef Chebyshev
//     return distance_Chebyshev(x, y, x_start, y_start) +
//            distance_Chebyshev(x, y, x_end, y_end);
// #endif
// }

// // 自定义比较函数，用于构建小顶堆
// class my_comparasion {  // 本题要求最小路径，用小顶堆，自定义比较逻辑为大于
// public:
//     const bool operator() (pair<int, int> lhs, pair<int, int> rhs) {
//         return Heuristic(lhs.first, lhs.second) > Heuristic(rhs.first, rhs.second);
//     };

// };

// int Astar() {
//     int x_cur, y_cur, x_next, y_next;
//     vector<vector<int>> moves(MAX_X + 1, vector<int>(MAX_Y + 1, 0));
//     priority_queue<pair<int, int>, vector<pair<int, int>>, my_comparasion> que;
//     // 先将起点压入栈
//     que.push(pair<int, int>{x_start, y_start});
//     while (!que.empty()) {
//         // 当前格子
//         x_cur = que.top().first;
//         y_cur = que.top().second;
//         que.pop();
//         // 检查是否为终点
//         if (x_cur == x_end && y_cur == y_end) {
//             while (!que.empty()) que.pop();
//             break;
//         }
//         // 下一步能走的格子
//         for (vector<int> v : dir) {
//             x_next = x_cur + v[0];
//             y_next = y_cur + v[1];
//             // 检查是否越界
//             if (!isInBox(x_next, y_next)) continue;
//             // 加入队列
//             if(!moves[x_next][y_next])
// 			{
// 				moves[x_next][y_next] = moves[x_cur][y_cur] + 1;
//                 que.push(pair<int, int>{x_next, y_next});
// 			}
//         }
//     }
//     return moves[x_end][y_end];
// }

// int main() {
//     cin >> n;
//     while (n--) {
//         cin >> x_start >> y_start >> x_end >> y_end;
//         cout << Astar() << endl;
//     }

//     return 0;
// }

#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int moves[1001][1001];
int dir[8][2]={-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2};
int b1, b2;
// F = G + H
// G = 从起点到该节点路径消耗
// H = 该节点到终点的预估消耗

struct Knight{
    int x,y;
    int g,h,f;
    bool operator < (const Knight & k) const{  // 重载运算符， 从小到大排序
     return k.f < f;
    }
};

priority_queue<Knight> que;

int Heuristic(const Knight& k) { // 欧拉距离
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2); // 统一不开根号，这样可以提高精度
}
void astar(const Knight& k)
{
    Knight cur, next;
	que.push(k);
	while(!que.empty())
	{
		cur=que.top(); que.pop();
		if(cur.x == b1 && cur.y == b2)
		break;
		for(int i = 0; i < 8; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if(next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000)
			continue;
			if(!moves[next.x][next.y])
			{
				moves[next.x][next.y] = moves[cur.x][cur.y] + 1;

                // 开始计算F
				next.g = cur.g + 5; // 统一不开根号，这样可以提高精度，马走日，1 * 1 + 2 * 2 = 5
                next.h = Heuristic(next);
                next.f = next.g + next.h;
                que.push(next);
			}
		}
	}
}

int main()
{
    int n, a1, a2;
    cin >> n;
    while (n--) {
        cin >> a1 >> a2 >> b1 >> b2;
        memset(moves,0,sizeof(moves));
        Knight start;
        start.x = a1;
        start.y = a2;
        start.g = 0;
        start.h = Heuristic(start);
        start.f = start.g + start.h;
		astar(start);
        while(!que.empty()) que.pop(); // 队列清空
		cout << moves[b1][b2] << endl;
	}
	return 0;
}
