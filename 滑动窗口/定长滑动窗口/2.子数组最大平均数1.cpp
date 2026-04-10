//力扣第643 子数组最大平均数1

/*定长滑窗套路
我总结成三步：入 - 更新 - 出。

1.入：下标为 i 的元素进入窗口，窗口元素和 s 增加 nums[i]。如果 i < k?1 则重复第一步。
2.更新：更新答案。本题由于窗口长度固定为 k，可以统计窗口元素和的最大值 maxS，最后返回的时候再除以 k。
3.出：下标为 i?k + 1 的元素离开窗口，窗口元素和 s 减少 nums[i?k + 1]。
    以上三步适用于所有定长滑窗题目。
*/
    
//主要去找出 不同题目的怎么去入 怎么去出

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_s = INT_MIN; // 窗口元素和的最大值
        int s = 0; // 维护窗口元素和
        for (int i = 0; i < nums.size(); i++) {
            // 1. 进入窗口
            s += nums[i];
            if (i < k - 1) { // 窗口大小不足 k
                continue;
            }
            // 2. 更新答案
            max_s = max(max_s, s);
            // 3. 离开窗口
            s -= nums[i - k + 1];
        }
        return (double)max_s / k;
    }
};

