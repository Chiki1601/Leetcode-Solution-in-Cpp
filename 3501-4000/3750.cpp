class Solution {
public:
    int minimumFlips(int n) {
        int ans = 0, temp = n, l = 0, r = -1;
        while(temp > 0) {
            temp >>= 1;
            r++;
        }
        while(l < r) {
            ans += ((n >> l) & 1) ^ ((n >> r) & 1);
            l++;
            r--;
        }
        return 2 * ans;
    }
};
