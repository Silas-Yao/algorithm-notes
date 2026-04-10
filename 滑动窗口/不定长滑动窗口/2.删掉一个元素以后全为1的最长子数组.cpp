//力扣第1493题 删掉一个元素以后全为1的最长子数组

/*删除后，子数组只有 1，也就是没有 0。那么删除之前呢？至多有一个 0。

所以问题相当于：

求最长子数组的长度（减一），满足子数组至多有一个 0。
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, cnt0 = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            // 1. 入，nums[right] 进入窗口
            cnt0 += 1 - nums[right]; // 维护窗口中的 0 的个数
            while (cnt0 > 1) { // 不符合题目要求
                // 2. 出，nums[left] 离开窗口
                cnt0 -= 1 - nums[left]; // 维护窗口中的 0 的个数
                left++;
            }
            // 3. 更新答案，注意不是 right-left+1，因为我们要删掉一个数
            ans = max(ans, right - left);
        }
        return ans;
    }
};
