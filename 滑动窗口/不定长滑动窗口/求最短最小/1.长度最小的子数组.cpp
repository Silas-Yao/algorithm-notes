//力扣 第209题 长度最小的子数组
/* 这题给我的启示是做题不要想当然，我框框套公式，想都没想，直接错了，
* 还是要理解没一步在干什么，while在干什么，前面我做的都是，while里面是不满足情况的，
* 我做指针不断移动，到满足情况在更新 ans，但这一题，是while里面是满足情况的，直接更新ans就好了，
* 要考虑边界情况，我这题一开时把ans设为了n，结果没过，忘了如果整个数组都不满足情况怎么办，所以
* 只需要设置一个比n大的输，后片判断一下就好了
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1, left = 0, s = 0;

        for (int i = 0; i < n; i++) {
            s += nums[i];
            while (s >= target) {
                ans = min(ans, i - left + 1);
                s -= nums[left];
                left++;
            }

        }
        return ans <= n ? ans : 0;
    }
};