//力扣第3634题 使数组平衡的最少移除数目


/*
1.由于我们只关心剩余元素的最小值和最大值，不关心元素的顺序，所以可以先从小到大排序，方便后续计算。
排序后，枚举最大值 mx=nums[i]，那么最小值 mn=nums[left] 必须满足mn?k≥mx
在 [mn,mx] 中的元素保留，其余元素去掉。由于排序了，所以这些元素在数组中是连续的，
问题转化成一个标准的滑动窗口模型。如果不满足上式，就把 left 加一，直到满足上式

2.我对滑动窗口的理解是 在右端点不断延伸的时候左端点会跟着右端点向右边移动，
使窗口维持在合法的区间。并且在右端点向右移动时，
已经在左端点左侧被移出滑动窗口的点，不会因为滑动窗口区间里值的变动变得重新合法。

*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size();
        int ans = 0, left = 0;
        for (int right = 0; right < n; right++) {
            while ((long long)nums[left] * k < nums[right]) { // 这里面要用long long 要不然可能会溢出
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return n - ans;

    }
};