//力扣第1358题 包含所有三种字符的字符串数目
/* 数组里面是在相应下标的位置++；
* 字符我们可以通过减去'a'来把字母转化成0,1,2,等
* 要注意这里我们的判断的逻辑是，while循环完了恰好是不满足情况的，那么left前面的
* 都是满足情况的
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0, left = 0;
        int arr[3];
        for (char c : s) {
            arr[c - 'a']++;
            while (arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 1) {
                arr[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};