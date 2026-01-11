class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        long long a = 0;
        int n = nums.size();
        vector<long long> c(n);

        for (int i = 30; i >= 0; --i) {
            long long t = a | (1LL << i);
            for (int j = 0; j < n; ++j) {
                long long v = nums[j], r = t & ~v;
                if (!r) c[j] = 0;
                else {
                    long long h = 1LL << (63 - __builtin_clzll(r));
                    c[j] = ((v & ~(h * 2 - 1)) | h | (t & (h - 1))) - v;
                }
            }
            if (m < n) nth_element(c.begin(), c.begin() + m, c.end());
            long long s = 0;
            for (int j = 0; j < m; ++j) s += c[j];
            if (s <= k) a = t;
        }
        return a;
    }
};
