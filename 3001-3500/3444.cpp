class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int m = target.size();
        int fullMask = (1 << m) - 1; // All bits set (for subset representation)
        
        vector<long long> lcmArr(1 << m);
        
        // Precompute LCM for each subset of `target`
        for (int mask = 1; mask < (1 << m); mask++) {
            long long L = 1;
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) {
                    L = lcm(L, target[j]);
                }
            }
            lcmArr[mask] = L;
        }
        
        long long INF = LLONG_MAX / 2;
        vector<long long> dp(1 << m, INF);
        dp[0] = 0; // No target selected yet, so cost is 0
        
        for (int x : nums) {
            vector<long long> newdp = dp;
            
            for (int mask = 1; mask < (1 << m); mask++) {
                long long L = lcmArr[mask];
                long long r = x % L;
                long long cost = (r == 0 ? 0 : L - r); // Adjusting x to be a multiple of L
                
                // Update DP array
                for (int old = 0; old < (1 << m); old++) {
                    int newMask = old | mask; // Merge current subset with previous subsets
                    newdp[newMask] = min(newdp[newMask], dp[old] + cost);
                }
            }
            dp = newdp;
        }
        
        return (int)dp[fullMask]; // Minimum cost to satisfy all LCM conditions
    }

private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};
