
// 力扣第35题  
//二分查找 最终如果找不到 会返回第一个大于目标值的位置 即要插入的位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)   return mid;
            else if (nums[mid] < target) left = mid + 1;
            else  right = mid - 1;
        }

        return left;


    }
};