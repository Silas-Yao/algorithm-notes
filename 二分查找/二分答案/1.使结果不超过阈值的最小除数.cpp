//力扣第1283题 使结果不超过阈值的最小除数
/*这里面的有边界 使nums里面最大的数，每个除以最大的数 求和等于sum，sum刚好小于等于threshold
除以比最大的数 求和都是sum，所以到最大的数就可以停了
这里面左边界可以优化的，可以这样理解，我们把sum尽可能分配给threshold个人，这除以的数就是
就是每个人平均分配到几个，那很容易去想到 没人人最少分配sum/threshold个，也就是均分

时间复杂度：O(nlogU)，其中 n 是 nums 的长度，U=max(nums)。二分 O(logU) 次，每次 O(n) 遍历 nums。
空间复杂度：O(1)。

*/


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 0, r = ranges::max(nums);//lleft 可以等于sum/threshold
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(nums, threshold, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
    bool check(vector<int>& nums, int threshold, int mid) {
        int s = 0;
        for (int x : nums) {
            s += (x + mid - 1) / mid;
            if (s > threshold) return false;
        }
        return true;
    }


};