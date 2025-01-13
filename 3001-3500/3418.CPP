
#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    // Helper function to calculate max coins from (i, j) with 'rem' neutralizations left
    int help(int i, int j, int rem, int n, int m, vvi& coins, vector<vvi>& dp) {
        // Base case: reached bottom-right corner
        if (i == n - 1 && j == m - 1) {
            if (coins[i][j] < 0) {
                // If this is a robber cell, neutralize if rem > 0
                return (rem > 0) ? 0 : coins[i][j];
            } else {
                return coins[i][j];
            }
        }

        // Boundary check: If out of bounds, return -infinity
        if (i >= n || j >= m)
            return -1e9;

        // If already computed, return cached result
        if (dp[i][j][rem] != INT_MIN)
            return dp[i][j][rem];

        int right = -1e9, down = -1e9;

        // If current cell is a robber, consider neutralization options
        if (coins[i][j] < 0) {
            if (rem > 0) { // Neutralize the robber
                right = help(i, j + 1, rem - 1, n, m, coins, dp);
                down = help(i + 1, j, rem - 1, n, m, coins, dp);
            }
        }

        // Take the current cell value + max of right/down without neutralization
        right = max(right, coins[i][j] + help(i, j + 1, rem, n, m, coins, dp));
        down = max(down, coins[i][j] + help(i + 1, j, rem, n, m, coins, dp));

        // Store and return the result
        return dp[i][j][rem] = max(right, down);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        // Initialize 3D DP table with INT_MIN
        vector<vvi> dp(n + 1, vvi(m + 1, vi(3, INT_MIN)));

        // Start recursion from the top-left corner with 2 neutralizations available
        return help(0, 0, 2, n, m, coins, dp);
    }
};
