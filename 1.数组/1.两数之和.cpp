//1. 暴力枚举
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a = nums.size();
        for (int i = 0; i < a; ++i) {
            for (int j = i + 1; j < a; ++j) {
                if (nums[i] + nums[j] == target) {
                    return { i,j };
                }
            }
        }
        return {};
    }
};
//2 .哈希表 ，哈希表可以通过空间换时间来减低时间复杂度 
// 哈希表可用于快速寻找数组中是否存在目标元素 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < a; ++i) {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end()) {
                return { it->second,i };
                {
                    hash[nums[i]] = i;
                }
                return {};
            }
        };



