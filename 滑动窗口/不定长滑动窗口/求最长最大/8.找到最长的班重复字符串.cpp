//力扣第2730题 找到最长的班重复字符串
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int ans = 1, left = 0;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            }
            if (cnt > 1) {
                left++;//因为left起始位置是零，要访问left-1，防止数组越界
                while (s[left] != s[left - 1]) {
                    left++;
                }
                cnt--;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
//优化 ，直接记录第一次重复字符串出现的位置
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1, left = 0;
        int firstRepeat = -1;  // 窗口内第一个重复对的第二个字符位置

        for (int right = 1; right < s.size(); ++right) {
            if (s[right] == s[right - 1]) {
                // 如果已经有一个重复对了，让 left 跳到第一个重复对的位置
              if (firstRepeat != -1) { //一定要前一个重复字符串跳跃完了，再记录第二个字符串的位置
                    left = firstRepeat;    
                }
                // 当前重复对成为新的"第一个"
                firstRepeat = right;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};