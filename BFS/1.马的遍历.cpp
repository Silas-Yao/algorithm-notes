#include<iostream>
#include<vector>
#include<queue>
// 洛谷 1443 马的遍历
using namespace std; // 8个方向
int dx[8] = { 2,2,-2,-2,1,1,-1,-1 };
int dy[8] = { 1,-1,1,-1,2,-2,2,-2 };

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[x][y] = 0;
    queue < pair<int, int>> q;
    q.push({ x,y });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx,ny });
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dist[i][j] << ' ';
            }
            cout << endl;
        }
    }



    return 0;


}