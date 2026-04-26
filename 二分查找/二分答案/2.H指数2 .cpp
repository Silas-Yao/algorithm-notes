//力扣第275题 H指数|| 
/*
 这一题我们发现h越小越可能满足条件，h越大越不好满足条件，这可以看出使求最大的解
 直接套公式 
 还有我要说的对于这个l r 和右边都必须一定是不可满足条件的，要不然就会出错了
 这一题 右边r不能设置为n，应为n可能满足条件，但n+1，一定不满足条件
 对于check函数的写法，就是我们说的条件，
 我想说的使，这个已经事先给我们排好序了，我们不用一个一个去遍历了，
 直接去判断最开始满足条件的，正常的来说有h篇满足条件，>=n,我们要去
 求h篇中的第一篇是否大于等于n，就可以了，正常使 n-h+1,但是要在数组里面找下标，
 刚好下标和正常的差个一，那么下标就是n-h了
 这样可以把 O(N log N) 的通用解法（遍历统计，适用于未排序数组）
  优化到O(log N) 的优化解法（利用有序特性，适用于已排序数组）

时间复杂度：O(logn)，其中 n 为 citations 的长度。每次循环，
都会将二分范围减少一半，所以循环会执行 O(logn) 次，所以时间复杂度为 O(logn)。
空间复杂度：O(1)。仅用到若干额外变量。
*/




class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = -1, r = citations.size() + 1;
        while (l + 1 < r) {
            int mid = (r + l) / 2;
            if (check(citations, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
    bool check(vector<int>& citations, int h) {
        int n = citations.size();
        if (h == 0) return true;
        return citations[n - h] >= h;
    }
};