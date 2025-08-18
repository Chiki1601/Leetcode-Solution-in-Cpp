class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strat, int k) {
        int n = prices.size();
        int h = k / 2;
        vector<long long> sp(n);
        long long base = 0;
        for (int i = 0; i < n; i++) {
            sp[i] = (long long)strat[i] * prices[i];
            base += sp[i];
        }

        if (n == k) {
            long long win_orig = base;
            long long win_mod = 0;
            for (int i = h; i < n; i++) win_mod += prices[i];
            long long change = win_mod - win_orig;
            return base + max(0LL, change);
        }

        long long win_orig = 0;
        for (int i = 0; i < k; i++) win_orig += sp[i];

        long long win_mod = 0;
        for (int i = h; i < k; i++) win_mod += prices[i];

        long long max_ch = win_mod - win_orig;

        for (int i = 1; i <= n - k; i++) {
            win_orig += sp[i+k-1] - sp[i-1];
            win_mod += prices[i+k-1] - prices[i-1+h];
            max_ch = max(max_ch, win_mod - win_orig);
        }

        return base + max(0LL, max_ch);
    }
};
