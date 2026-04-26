// 力扣第904题 水果成篮 

/*子数组越长，包含的元素越多，越可能不满足题目要求；反之，子数组越短，包含的元素越少，越可能满足题目要求。本题属于「越短越合法」，有这种性质的题目，可以用滑动窗口解决

枚举子数组的右端点 right。同时用一个哈希表 cnt 维护子数组内每个元素的出现次数。

如果 fruits[right] 加入哈希表后，发现哈希表的大小超过了 2，那么子数组不满足要求。移动子数组的左端点 left，把 fruits[left] 的出现次数减一，直到哈希表中的元素种数等于 2

?注意：如果 fruits[left] 的出现次数变成 0，需要从 cnt 中移除，表示子数组内少了一种元素。如果不移除，我们无法通过 cnt 的大小判断窗口中的元素种数
作者：灵茶山艾府
链接：https ://leetcode.cn/problems/fruit-into-baskets/solutions/3042744/hua-dong-chuang-kou-ha-xi-biao-pythonjav-uzmw/
来源：力扣（LeetCode）
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0, left = 0;
        unordered_map<int, int> cont;
        for (int right = 0; right < n; right++) {
            int c = fruits[right];
            cont[c]++;
            while (cont.size() > 2) {
                if (--cont[fruits[left]] == 0) {
                    cont.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
