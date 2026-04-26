// 力扣 第2779题 数组的最大美丽值
/* 排序后的数组里面的每个数 x 可以改成闭区间 [x-k,x+k] 中的数，
* 判断是否相交，排序后，选出的区间是连续的，我们只需考虑最左边的区间 [x-k,x+k] 
和最右边的区间 [y-k,y+k]，x+k≥y-k，即 y-x≤2k， 原问题转化为
排序后，找最长的连续子数组，其最大值减最小值 ≤2k。由于数组是有序的，
相当于子数组的最后一个数减去子数组的第一个数 ≤2k。 
枚举 nums[right] 作为子数组的最后一个数，一旦 nums[right]-nums[left]>2k，就移动左端点 left
左端点停止移动时，下标在 [left,right] 的子数组就是满足要求的子数组， 
用子数组长度 right-left+1 更新答案的最大值。
时间复杂度：O(nlogn) 其中 n 为 nums 的长度。瓶颈在排序上(内部是用了二分去排序的)，
滑窗那部分的时间复杂度为 O(n)
空间复杂度：O(1) 忽略排序的栈开销，仅用到若干额外变量。
*/
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, left = 0;
        ranges::sort(nums);
        for (int i = 0; i < n; i++) {
            while (nums[i] - nums[left] > 2 * k) {
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};