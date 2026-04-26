//力扣第930题 和相同的二元子数组 
/* 恰好滑动性窗口
* 要计算有多少个元素和恰好等于 k 的子数组，可以把问题变成：

计算有多少个元素和 ≥k 的子数组。
计算有多少个元素和 >k，也就是 ≥k+1 的子数组。
答案就是元素和 ≥k 的子数组个数，减去元素和 ≥k+1 的子数组个数。这里把 > 转换成 ≥，从而可以把滑窗逻辑封装成一个函数 solve，然后用 solve(k)?solve(k+1) 计算，无需编写两份滑窗代码。

总结：「恰好」可以拆分成两个「至少」，也就是两个「越长越合法」的滑窗问题。

注：也可以把问题变成 ≤k 减去 ≤k?1，即两个「至多」。可根据题目选择合适的变形方式。

作者：灵茶山艾府
链接：https://leetcode.cn/discuss/post/3578981/ti-dan-hua-dong-chuang-kou-ding-chang-bu-rzz7/
来源：力扣（LeetCode）
*/
class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0, left = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            while (s >= goal && left <= i) {//这里面要注意边界问题，left不能超过i，会越界，将空窗口记录
                s -= nums[left];
                left++;
            }
            ans += left;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal + 1);
    }
};