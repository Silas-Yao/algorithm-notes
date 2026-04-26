// 改编为子数组版本  用单调队列 ，通过双端队列实现
/* 实现思路:
淘汰队尾 尾部 (pop_back)  保持单调性， 把比新元素小的从后面踢掉
新元素入队  尾部 (push_back)  正常添加
淘汰过期元素  头部 (pop_front)  窗口右移时，左边元素离开窗口
查询最值 头部 (front) 队头就是最值
时间复杂度: 每个元素最多入队一次,出队一次再加上主循环和过期元素出队，总操作次数 ≤ 4N，所以是 O(N)
总体空间复杂度：O(N) 两个队列的空间
*/
class Solution {
public:
    // 改编为子数组版本后的思路 
    int maximumBeauty_Subarray(vector<int>& nums, int k) {
        deque<int> max_q, min_q;
        int left = 0, ans = 0;
        for (int right = 0; right < nums.size(); ++right) {
            // 维护窗口内最大值
            while (!max_q.empty() && nums[max_q.back()] <= nums[right]) max_q.pop_back();
            max_q.push_back(right);
            // 维护窗口内最小值
            while (!min_q.empty() && nums[min_q.back()] >= nums[right]) min_q.pop_back();
            min_q.push_back(right);

            // 收缩条件：区间内极差 > 2k
            while (!max_q.empty() && !min_q.empty() &&
                nums[max_q.front()] - nums[min_q.front()] > 2 * k) {
 /* 下面这两步是在，但最指针右移动时，我们要删去队列里面窗口滑出来的元素，
 * 这里面隐含了一个信息，元素入队的顺序就是它们在原数组中的顺序，而原数组的下标是递增的，
 * 所以队列左边的下标是小于右边的下标的，而left是从左边向右边移动的，所以队首元素是
 最可能等于left的
 */
                if (max_q.front() == left) max_q.pop_front(); 
                if (min_q.front() == left) min_q.pop_front();
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    
};