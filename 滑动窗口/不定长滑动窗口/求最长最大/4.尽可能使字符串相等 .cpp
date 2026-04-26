// 力扣第1208 尽可能使字符串相等 
// 左右指针 最多都各走 n次 时间复杂度为2n，也就是0n

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0, left = 0;
        int cost = 0;
        for (int right = 0; right < n; right++) {
            cost += abs(s[right] - t[right]);
            if (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};