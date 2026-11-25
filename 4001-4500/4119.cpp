class Solution {
public:
    int minSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        const int b = 17, full = (1 << b) - 1;
        vector<int> suff(n);
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = (i == n - 1 || (i + 1) % k == 0) ? nums[i] : (suff[i + 1] & nums[i]);
        }

        vector<char> bad(full + 1, 0);
        int pref = 0;
        for (int j = 0; j < n; ++j) {
            pref = (j % k == 0) ? nums[j] : (pref & nums[j]);
            if (j >= k - 1) {
                int x = suff[j - k + 1] & pref;
                if (!x) return -1;
                bad[full ^ x] = 1;
            }
        }

        for (int i = 0; i < b; ++i) {
            for (int m = 0; m <= full; ++m) {
                if ((m >> i) & 1) {
                    bad[m ^ (1 << i)] |= bad[m];
                }
            }
        }

        vector<char> pc(full + 1, 0);
        int ans = b;
        for (int m = 1; m <= full; ++m) {
            pc[m] = pc[m & (m - 1)] + 1;
            if (!bad[m] && pc[m] < ans) {
                ans = pc[m];
            }
        }
        return ans;
    }
};
   
