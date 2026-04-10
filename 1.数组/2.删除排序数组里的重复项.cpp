// 力扣 26题 删除排序数组中的重复项 
 //  关键 需要保存可覆盖和观测位置  快慢指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // i是快指针 用于扫描  k是慢指针 用于覆盖数据的位置
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // nums[i] 不是重复项
                nums[k++] = nums[i]; // 保留 nums[i] k++ 是先赋值再+1;
            }
        }
        return k;
    }
};
