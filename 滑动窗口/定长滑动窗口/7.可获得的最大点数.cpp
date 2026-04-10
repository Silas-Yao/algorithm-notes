//力扣第1423 可获得的最大点数
//逆向思维
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = INT_MAX, s = 0;
        int n = cardPoints.size();
        if (n == k) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        for (int i = 0; i < n; i++) {
            s += cardPoints[i];
            int left = i + k + 1 - n;
            if (left < 0) {
                continue;
            }
            ans = min(ans, s);
            s -= cardPoints[left];
        }
        int result = accumulate(cardPoints.begin(), cardPoints.end(), 0) - ans;
        return result;
    }
};

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;
        int s = reduce(cardPoints.begin(), cardPoints.begin() + m);
        int min_s = s;
        for (int i = m; i < n; i++) {
            s += cardPoints[i] - cardPoints[i - m];
            min_s = min(min_s, s);
        }
        return reduce(cardPoints.begin(), cardPoints.end()) - min_s;
    }
};

//正向思维
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // 第一步：先取左边 k 张牌的和
        int s = reduce(cardPoints.begin(), cardPoints.begin() + k);
        // s = 左边 k 张牌的和

        int ans = s;  // 当前最大值就是全取左边

        // 第二步：逐步将左边的牌换成右边的牌
        for (int i = 1; i <= k; i++) {
            // 减去左边第 (k-i) 张（从左边移除一张）
            // 加上右边第 i 张（从右边加入一张）
            s += cardPoints[cardPoints.size() - i] - cardPoints[k - i];

            // 更新最大值
            ans = max(ans, s);
        }

        return ans;
    }
};
