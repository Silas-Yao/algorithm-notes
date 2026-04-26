//力扣第2279题 装满石头的背包的最大数量

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int>need(n);
        for (int i = 0; i < n; i++) {
            need[i] = capacity[i] - rocks[i];
        }
        ranges::sort(need);
        int cnt = 0;
        for (int x : need) {
            if (additionalRocks - x >= 0) {
                additionalRocks -= x;
                cnt++;
            }
            else {
                break;
            }
        }
        return cnt;
    }
};