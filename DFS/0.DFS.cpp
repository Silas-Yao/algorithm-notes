#include <iostream>
#include <vector>
using namespace std;
//DFS用来遍历所有可能性（回溯、连通性、拓扑排序） 通过递归的方式

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, int x, int y) {
    int n = maze.size();
    int m = maze[0].size();

    // 1. 标记当前点已访问
    visited[x][y] = true;
    cout << "访问到: (" << x << "," << y << ")" << endl;

    // 2. 探索四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 3. 如果邻居合法且未访问，递归进去
        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            maze[nx][ny] == 0 && !visited[nx][ny]) {
            dfs(maze, visited, nx, ny);
        }
    }
    // 4. 函数结束会自动回溯（不需要写额外代码）
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };

    int n = maze.size();
    int m = maze[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    dfs(maze, visited, 0, 0);  // 从(0,0)开始DFS

    return 0;
}