//力扣第2841 几乎唯一子数组的最大和
/*  第一次没做出来，我想到要用哈希表了，但可能以前练的比较少，也有段时间没用了，忘了咋用了
* 这题就很正常的思路 前面滑动窗口很长正常
* 难点在于 如何去记录重复的元素，如果去每个遍历一边太麻烦，可以用哈希，通过空间换时间来做
* 将滑动窗口遍历的元素放到哈希表中，只有不相同的元素才会在哈希表的不同位置，满足至少有m个不相同的
* 元素，就是哈希表的长度大于等于m，之后是去维护哈希表，滑动窗口出元素是 哈希表元素的值减1，等到哈希表
* 元素的值变为零，可以删去了，说明这个值已经不在窗口里面了
 
 时间复杂度：O(n)，其中 n 为 nums 的长度。
空间复杂度：O(k)。哈希表的大小不会超过窗口长度 k

*/

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0, s = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            cnt[nums[i]]++;

            int left = i - k + 1;
            if (left < 0) {
                continue;
            }
            if (cnt.size() >= m) {
                ans = max(ans, s);
            }
            int out = nums[left];
            s -= out;
            if (--cnt[out] == 0) {
                cnt.erase(out);
            }

        }
        return ans;
    }
};