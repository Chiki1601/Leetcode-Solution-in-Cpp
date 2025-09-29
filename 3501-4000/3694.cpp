typedef long long ll;
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<ll> dp(n+1, LLONG_MAX/2);
        vector<int> nums(n+1, 0);
        for (int i = 1; i <= n; i++) nums[i] = costs[i-1];
        
        dp[0] = 0; // Base: no cost at step 0
        for (int i = 1; i <= n; i++) {
            if (i-1 >= 0) dp[i] = min(dp[i], dp[i-1] + nums[i] + 1LL*(1*1));
            if (i-2 >= 0) dp[i] = min(dp[i], dp[i-2] + nums[i] + 1LL*(2*2));
            if (i-3 >= 0) dp[i] = min(dp[i], dp[i-3] + nums[i] + 1LL*(3*3));
        }
        return (int)dp[n];
    }
};
