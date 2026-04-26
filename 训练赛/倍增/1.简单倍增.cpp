/*时间复杂度：O(n log t)
空间复杂度：O(n log t)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    long long t;
    cin >> n >> s >> t;

    // nxt[k][i]: 从i出发，走2^k步后的位置，-1表示出界
    vector<vector<int>> nxt(61, vector<int>(n, -1));
    // 初始化k=0（走1步）
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            nxt[0][i] = (i + 1 < n) ? i + 1 : -1;
        }
        else {
            nxt[0][i] = (i - 1 >= 0) ? i - 1 : -1;
        }
    }
    /* 递推公式
      走2^k步 = 先走2^(k-1)步 + 再走2^(k-1)步
      nxt[k][i] = nxt[k-1][ nxt[k-1][i] ]
            ↑           ↑
        从i出发，   先查到走一半后到了哪（中点）
        走2^k步     再从中点走另一半
    */
    // 递推更大的k
    for (int k = 1; k < 61; k++) {
        for (int i = 0; i < n; i++) {
            if (nxt[k - 1][i] != -1) {
                nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
            }
        }
    }
    vector<long long> ans(n, 0);
    // 对每个位置查询
    for (int i = 0; i < n; i++) {
        int pos = i;           // 从位置i出发
        long long steps = t;   // 要走的步数
        // 把t拆成二进制，对应每一步
        for (int k = 0; k < 61 && steps > 0; k++) {
            if (steps & 1) {            // steps的二进制第k位是1
                pos = nxt[k][pos];     // 走2^k步
                if (pos == -1) break;   // 出界了
            }
            steps >>= 1;               // 右移一位
        }
        if (pos != -1) {
            ans[pos]++;   // 这个人最终在pos位置
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}