//力扣第3745题 三元素表达式的最大值

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);
        int c = nums[n - 1] + nums[n - 2] - nums[0];
        return c;
    }
};