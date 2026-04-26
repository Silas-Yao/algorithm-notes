//力扣第713题 乘积小于k的子数组

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int n = nums.size();
        int ans = 0, left = 0, prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while (prod >= k) {
                prod /= nums[left];
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};