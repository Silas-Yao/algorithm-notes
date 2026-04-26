//力扣第875题 爱吃香蕉的珂珂
/* 这题要向上取整
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = ranges::max(piles);
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(piles, mid, h)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
    bool check(vector<int>& piles, int k, int h) {
        long long hours = 0;
        for (int x : piles) {
            hours += (x + k - 1) / k;
        }
        if (hours > h) return false;

        return true;

    }
};