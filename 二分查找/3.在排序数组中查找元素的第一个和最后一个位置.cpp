//力扣第34题 在排序数组中查找元素的第一个和最后一个位置
/*
  元素的最后一个位置，可以通过去寻找大于等于target+1的位置，他的左边
  就是元素target的最后一个位置

*/

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
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = findMinGreen(nums, target);
        int idx2 = findMinGreen(nums, target + 1) - 1;
        if (idx1 == nums.size()) {
            return{ -1,-1 };
        }
        if (nums[idx1] != target) {
            return{ -1,-1 };
        }
        return { idx1,idx2 };
    }
};