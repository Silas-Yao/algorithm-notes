#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 505;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Node {
    int x, y, hasKey;
};
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        char g[N][N];
        int sx = -1, sy = -1, ex = -1, ey = -1;

        for (int i = 0; i < n; i++) {
            cin >> g[i];
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'P') {
                    sx = i; sy = j;
                }
                else if (g[i][j] == 'E') {
                    ex = i; ey = j;
                }
            }
        }

        // dist[x][y][0/1] = 没钥匙/有钥匙时的最短步数
        int dist[N][N][2];
        memset(dist, -1, sizeof dist);

        queue<Node> q;
        dist[sx][sy][0] = 0;
        q.push({ sx, sy, 0 });

        int ans = -1;

        while (!q.empty()) {
            Node cur = q.front(); q.pop();
            int x = cur.x, y = cur.y, hasKey = cur.hasKey;
            int step = dist[x][y][hasKey];

            // 到达终点且有钥匙
            if (x == ex && y == ey && hasKey == 1) {
                ans = step;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (g[nx][ny] == '#') continue;

                // 没钥匙时不能进入 E
                if (g[nx][ny] == 'E' && !hasKey) continue;

                int newHasKey = hasKey;
                if (g[nx][ny] == 'K') newHasKey = 1;

                if (dist[nx][ny][newHasKey] == -1) { 
                    dist[nx][ny][newHasKey] = step + 1;
                    q.push({ nx, ny, newHasKey });
                }
            }
        }

        if (ans == -1) {
            cout << "No solution" << endl;
        }
        else {
            cout << ans << endl;
        }
    }

    return 0;
}