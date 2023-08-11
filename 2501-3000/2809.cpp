class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        const int n = nums1.size();
        vector<int> ind(n);
        int s = 0, d = 0;
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
            s += nums1[i];
            d += nums2[i];
        }
        if (s <= x) {
            return 0;
        }
        sort(ind.begin(), ind.end(), [&](const int a, const int b) {
            return nums2[a] < nums2[b];
        });
        vector<int> dp(n + 1);
        int r = n + 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, r - 1); j; --j) {
                dp[j] = max(dp[j], dp[j - 1] + nums2[ind[i - 1]] * j + nums1[ind[i - 1]]);
                if (s + j * d - dp[j] <= x) {
                    r = j;
                }
            }
        }
        return r <= n ? r : -1;
    }
};
