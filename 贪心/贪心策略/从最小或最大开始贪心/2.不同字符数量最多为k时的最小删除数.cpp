//力扣第3534题 不同字符数量最多为k时的最小删除数
/*统计每个字母的出现次数，记到一个长为 26 的 cnt 数组中。
优先去掉出现次数少的字母，也就是去掉出现次数前 26?k 小的字母。（出现次数为 0 的也算上）
 
 要让总和最小（删除最少），就应该优先选“代价小”的操作

*/

class Solution {
public:
    int minDeletion(string s, int k) {
        int cnt[26];
        for (char x : s) {
            cnt[x - 'a']++;
        }
        ranges::sort(cnt);
        int ans = 0;
        for (int i = 0; i < 26 - k; i++) {
            ans += cnt[i];
        }
        return ans;

    }
};