//力扣 第3679题 使库存平衡的最少丢弃次数 

/* 这一题与前面不同的是 ，要先判断，再考录是否要进窗口，因为还涉及到删除，如果物理删除会破坏数组下标
* 的索引顺序，又因为数组里面的元素都是正数，所以可以把数组值为0或负数，未来离开窗口不影响答案；
* 注意一开始的长为 1,2,3,…,w−1 的窗口也要考察是否需要丢弃物品
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0; i < arrivals.size(); i++) {
            int& x = arrivals[i]; // 这里加引用是为了能求改原数组
            // x 进入窗口
            if (cnt[x] == m) { // x 的个数已达上限
                // 注意 x 在未来要离开窗口，但由于已经丢弃，不能在离开窗口时修改 cnt
                // 这里直接置为 0，未来离开窗口就是 cnt[0]--，不影响答案
                x = 0; // 丢弃 arrivals[i]
                ans++;
            }
            else {
                cnt[x]++;
            }

            // 左端点元素离开窗口，为下一个循环做准备
            int left = i + 1 - w;
            if (left >= 0) {
                cnt[arrivals[left]]--;
            }
        }
 // 为什么不用erase操作，因为我们只要求取求最小的丢弃次数，
 // cnt.find(key) == cnt.end() cnt.size() 表示当前又多少个物品品种时才需要删除操作
        return ans;
    }
};
int main() {
    vector<int> arrivals;
    int w, m, n;
    cin >> w >> m >> n;
    while (n--) {
        int x;
        cin >> x;
        arrivals.push_back(x);
    }
    return 0;

}