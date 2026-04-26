// 力扣第1004 最大连续1的个数|||
//这一题是1493题删掉一个元素后全为1的最长数组
// 这是我唯一一个秒杀的题，从来没有秒的真么干脆，简直不敢相信
//只用了 3分钟直接秒杀了，虽然是基础题，浅浅记录一下把，
// 极大了增强了我的自信 ，心情难以言表，只能说灵神牛逼
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, left = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int c = nums[i];
            cnt[c]++;
            while (cnt[0] > k) {
                cnt[nums[left]]--;
                left++;
            }

            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};