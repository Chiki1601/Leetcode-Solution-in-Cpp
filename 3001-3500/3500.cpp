class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, long long k) {
        int n = nums.size();
        vector<long long> preSum(n + 1), sufCost(n + 1);
        for(int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            sufCost[i] = sufCost[i + 1] + cost[i];
        }

        vector<long long> dp(n + 1, LLONG_MAX);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            long long cost_ij = 0;  //cost of cur partition from i to j
            for(int j = i; j < n; j++) {
                cost_ij += cost[j];
                dp[i] = min(dp[i],
                    (preSum[j + 1] * cost_ij) +
                    (k * sufCost[i]) + 
                    dp[j + 1]
                );
            }
        }

        return dp[0];
    }
};
