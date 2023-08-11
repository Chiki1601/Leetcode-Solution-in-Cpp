class Solution {
public:
    int dp[101][101];
    vector<int> prefixSum;
    int solve(int i, int j, vector<int>&nums, int m) {
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int sum = 0;
        if (i == 0) sum = prefixSum[j];
        else sum = prefixSum[j] - prefixSum[i - 1];

        if (j - i == 1 && sum >= m) return dp[i][j] = 1;
        if (sum < m) return dp[i][j] = false;

        dp[i][j] = false;
        for (int k = i; k < j; k++) {
            if (solve(i, k, nums, m) == 1 && solve(k + 1, j, nums, m) == 1) {
                return dp[i][j] = (dp[i][j] || true);
            }
        }
        return dp[i][j];
    }

    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        prefixSum.assign(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        if (n == 2) return true;
        return solve(0, n - 1, nums, m);
    }
};
