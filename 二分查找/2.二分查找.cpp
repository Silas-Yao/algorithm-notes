//力扣第704 二分查找
class Solution {
    int findMinGreen(vector<int>& nums, int target) {
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
public:
    int search(vector<int>& nums, int target) {
        int  index = findMinGreen(nums, target);
        if (index == nums.size()) {
            return -1;
        }
        if (nums[index] != target) {
            return -1;
        }
        return index;
    }
};