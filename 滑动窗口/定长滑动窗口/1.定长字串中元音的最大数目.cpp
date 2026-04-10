// 力扣 第1456题 定长字串中元音的最大数目

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;
        for (int i = 0; i < s.size(); i++) { // 枚举窗口右端点 i
            // 1. 右端点进入窗口
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowel++;
            }

            int left = i - k + 1; // 窗口左端点
            if (left < 0) { // 窗口大小不足 k，尚未形成第一个窗口
                continue;
            }

            // 2. 更新答案
            ans = max(ans, vowel);
            if (ans == k) { // 答案已经等于理论最大值
                break; // 无需再循环
            }

            // 3. 左端点离开窗口，为下一个循环做准备
            char out = s[left];
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u') {
                vowel--;
            }
        }
        return ans;
    }
};
