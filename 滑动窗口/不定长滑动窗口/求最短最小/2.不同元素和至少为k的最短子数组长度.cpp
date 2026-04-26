// 力扣第3795 不同元素和至少为k的最短子数组长度
/* 要注意入窗口时s求和前要判断 是否时第一次出现
*   出窗口时要要注意 只有窗口里面没有相应元素了，s才减去
*  ans可以设置为n+1;
*/


class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1, left = 0;
        long long s = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (cnt[nums[i]] == 0) {
                s += nums[i];
            }
            cnt[nums[i]]++;
            while (s >= k) {
                ans = min(ans, i - left + 1);
                if (--cnt[nums[left]] == 0) {
                    s -= nums[left];
                }
                left++;
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};