//力扣 第27题

// 快慢指针   如果 只有第一个元素等于val时 需要每个不等于val元素都左移一次 效率低
class Solution {
public:
    int removeElement(vector<int>&nums, int val) {
        int j = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

// 对撞指针  对于序列中不要求顺序   且val元素较少时非常有效
class Solution {
    public int removeElement(vector<int>&nums, int val) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            if (nums[left] != val) {
                left++;
            }
            else if (nums[right] == val) {
                right--;
            }
            else {
                nums[left] = nums[right];
                right--;
            }
        }
        return left;
    }
}