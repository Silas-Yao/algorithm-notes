//力扣第35题搜索插入位置

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};