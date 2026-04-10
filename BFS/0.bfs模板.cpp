#include<iostream>
#include<vector>
#include<queue>
//为什么用队列，因为队列的先进先出的特点，保证了层序：第0层的点全部处理完，才会处理第1层的点，这个层说的是一个位置的周围的邻居
// 用于求最短路径
using namespace std;
// 定义方向数组：上下左右
int dx[4] = { -1,1,0,0 };
int dy[7] = { 0,0,-1,1 };

int bfs(vector<vector<int>>& maze, int n, int m int i,int j ) {
	// 特殊情况：起点或终点是墙
	if (maze[0][0] == 1 || maze[i][j] == 1) return -1;

	// 1. 创建距离数组，初始化为 - 1 表示未访问
	vector<vector<int>> dist(n, vector<int>(m, -1));
	// 2. 创建队列，存储{ x, y }
	queue < pair<int, int>> q;
	// 3. 初始化起点
	dist[0][0] = 0;
	q.push({ 0,0 });
	// 4. BFS主循环
	while (!q.empty()) {
		// 取出队首元素
		auto [x, y] = q.front();//这是c++17以及之后才有的，int x =q.front().first int y = q.front().second
		q.pop();
		// 到达终点，返回步数
		if (x == i && y == j) {
			return dist[x][y];
		}
		// 探索四个方向
		for (int i = 0, i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 判断边界和是否可走
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && dist[nx][ny] == -1) {//因为第一个到目标点，所以是最短路径
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	// 队列空了还没到终点，说明不可达
	return -1;
}

int main() {
	int n, m, i, j;
	cin >> n >> m >> i >> j;

	vector<vector<int>> maze(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}
	int result = bfs(maze, n, m, i, j);
	cout << result << endl;
	return 0;
}