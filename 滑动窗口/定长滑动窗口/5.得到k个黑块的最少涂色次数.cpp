 
//力扣第2379题 得到k个黑块的最少涂色次数

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt_w = 0;
        for (int i = 0; i < k; i++) {
            cnt_w += blocks[i] & 1;
        }
        int ans = cnt_w;
        for (int i = k; i < blocks.length(); i++) {
            cnt_w += (blocks[i] & 1) - (blocks[i - k] & 1);
            ans = min(ans, cnt_w);
        }
        return ans;
    }
};


// 滑动窗口+避免分支预测
/* s[i] & 1 是什么意思 对于本题，可以把 ‘W’ 看成 1，把 ‘B’ 看成 0
* 
* 问：为什么把 if-else（或者 ?: 三目运算符）写成 s[i] & 1 就会快很多？（本题数据范围小看不出区别）

答：CPU 在遇到分支（条件跳转指令）时会预测代码要执行哪个分支，如果预测正确，CPU 就会继续按照预测的路径执行程序。但如果预测失败，CPU 就需要回滚之前的指令并加载正确的指令，以确保程序执行的正确性。

对于本题的数据，字符 ‘W’ 和 ‘B’ 可以认为是随机出现的，在这种情况下分支预测就会有 50% 的概率失败。失败导致的回滚和加载操作需要消耗额外的 CPU 周期，如果能用较小的代价去掉分支，对于本题的情况必然可以带来效率上的提升。

注意：这种优化方法往往会降低可读性，最好不要在业务代码中使用。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/1763639/on-hua-dong-chuang-kou-by-endlesscheng-s4fx/
来源：力扣（LeetCode）

*/
// 这一题通过前缀和来看  所以后边是是 blocks[i-k]
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt_w = 0;
        for (int i = 0; i < k; i++) {
            cnt_w += blocks[i] & 1;
        }
        int ans = cnt_w;
        for (int i = k; i < blocks.length(); i++) {
            cnt_w += (blocks[i] & 1) - (blocks[i - k] & 1);
            ans = min(ans, cnt_w);
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https ://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/1763639/on-hua-dong-chuang-kou-by-endlesscheng-s4fx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。