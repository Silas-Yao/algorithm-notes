// 力扣 第53题 最大子序和

//1.贪心  如果前一个子序和小于零 就舍去 ，大于零就加上当前元素
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {

            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};
//2.动态规划  
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0]; //一当前位置结尾的最大数组和
        int max_sum = nums[0];//全局最大子数组和
        for (int i = 1; i < n; i++) {
            cur = max(nums[i], cur + nums[i]);
            max_sum = max(cur, max_sum);
        }
        return max_sum;
    }
};