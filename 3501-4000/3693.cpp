class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return solve(0, n, costs, dp);
    }

    int solve(int i, int n, vector<int>& costs, vector<int>& dp) {
        if (i > n) return INT_MAX; 
        if (i == n) return 0; 
        if (dp[i] != -1) return dp[i];

        int oneStep = (costs[i] + 1) + solve(i + 1, n, costs, dp);
        int twoStep = (i + 2 <= n) ? (costs[i + 1] + 4) + solve(i + 2, n, costs, dp) : INT_MAX;
        int threeStep = (i + 3 <= n) ? (costs[i + 2] + 9) + solve(i + 3, n, costs, dp) : INT_MAX;

        return dp[i] = min({oneStep, twoStep, threeStep});
    }
};
