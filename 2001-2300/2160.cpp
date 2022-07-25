class Solution {
public:
    int minimumSum(int n) {
        int d[4] = {}, ans = 0;
        for (int i = 0; i < 4; ++i, n /= 10) d[i] = n % 10;
        sort(begin(d), end(d));
        return 10 * (d[0] + d[1]) + d[2] + d[3];
    }
};
