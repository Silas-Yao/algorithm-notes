//力扣第1343 大小为k平均值大于阈值的子数组数目

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int s = 0;
        int vowel = 0;
        for (int i = 0; i < arr.size(); i++) {
            s += arr[i];
            int left = i - k + 1;
            if (left < 0) {
                continue;
            }
            if (s >= threshold * k) {
                vowel++;
            }
            s -= arr[left];
        }
        return vowel;
    }
};