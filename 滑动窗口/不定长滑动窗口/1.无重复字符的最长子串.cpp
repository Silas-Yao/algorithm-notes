// 力扣第3题 无重复字符的最长字串
//1. 用哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, left = 0;
        unordered_map<char, int> cnt; // 维护从下标 left 到下标 right 的字符
        for (int right = 0; right < n; right++) {
            char c = s[right];
            cnt[c]++;
            while (cnt[c] > 1) { // 窗口内有重复字母  用while 不用if 将重复元素一直删的没有;
                cnt[s[left]]--; // 移除窗口左端点字母
                left++; // 缩小窗口
            }
            ans = max(ans, right - left + 1); // 更新窗口长度最大值
        }
        return ans;
    }
};
//2. 用数组储存字符出现的位置
vector<int> charIndex(128, -1); // 1. 申请长度为128的数组，全填 -1
int left = 0, maxLen = 0;

for (int right = 0; right < s.size(); right++) {
    char c = s[right]; // 2. 拿到当前字符，比如 'a'

    // 3. 查表：看看 'a'(ASCII 97) 这个位置上次出现是哪里？
    if (charIndex[c] >= left) {
        // 如果上次出现的位置 >= 当前窗口左边界，说明窗口里已经有 'a' 了，重复了！
        left = charIndex[c] + 1; // 左边界直接跳到重复字符的下一个位置
    }

    charIndex[c] = right; // 4. 无论是否重复，都要更新 'a' 的最新位置为当前的 right

    maxLen = max(maxLen, right - left + 1); // 5. 计算当前窗口长度
}

