//力扣第2090 半径为k的子数组平均值

/*  1题我第一次错了，我刚开始想在原来的数组上去改的，想让i-k前面的都改为-1，结果发现导致让左边元素出窗口的时候
  我前面已经把这个元素修改过了，导致s求和错了
  2. 这个求个s大小最大为10的10次方 已经超过了 int的最大值 所以要用 long long
  */ 
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n, -1);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            if (i < 2 * k) {
                continue;
            }
            arr[i - k] = s / (2 * k + 1);
            s -= nums[i - k * 2];

        }

        return arr;
    }
};