//第3074 重新分装苹果
/*既然同一个包裹中的苹果可以分装到不同的箱子中，
那就先把所有苹果堆在一起，然后一个个地装箱。
*/
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int s = reduce(apple.begin(), apple.end());
        ranges::sort(capacity, greater());
        int i = 0;
        while (s > 0) {
            s -= capacity[i++];
        }
        return i;
    }
};