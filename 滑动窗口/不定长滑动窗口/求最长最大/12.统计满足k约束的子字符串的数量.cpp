//力扣第3258题 统计满足k约束的子字符串的数量

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int arr[2], n = s.size();
        int ans = 0, left = 0;
        for (int i = 0; i < n; i++) {
            arr[s[i] - '0']++;
            while (arr[0] > k && arr[1] > k) {
                arr[s[left] - '0']--;
                left++;
            }

            ans += i - left + 1;
        }
        return ans;

    }
};