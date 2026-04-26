//力扣第2024题 考试的最大困扰度
/* 如果 T 和 F 的出现次数都超过 k，那么必须不断移动左端点 left，
同时减少 answerKey[left] 的出现次数，直到 T 和 F 的出现次数至少有一个 ≤k
*/
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int ans = 0, left = 0;
        unordered_map<char, int> cnt;
        cnt['T'] = 0;
        cnt['F'] = 0;
        for (int i = 0; i < n; i++) {
            char c = answerKey[i];
            cnt[c]++;
            while (cnt['T'] > k && cnt['F'] > k) {
                cnt[answerKey[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;

    }
};
// 位运算 由于 T 和 F 的 ASCII 值除以 2 后的奇偶性不同，也就是它们二进制的次低位不同
// ，可以改为统计二进制次低位。
// 除以2，相当二进制右移一位，很好理解，右移每一位，相当于 每一位上的2的幂次减法去1，
//那不久相当于 整体出二了吗，
// &1 相当于取二进制数的最后一位， 
// T的ASCII 84 二进制为 01010100  F的ASCII的二进制为 01000110
// 最后以为一样没法判断，但次低位 不一样 所以左移一位 ，
//太具有技巧行了 ，不建议用，纯炫技
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, left = 0, cnt[2]{};
        for (int right = 0; right < answerKey.length(); right++) {
            cnt[answerKey[right] >> 1 & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[answerKey[left] >> 1 & 1]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

