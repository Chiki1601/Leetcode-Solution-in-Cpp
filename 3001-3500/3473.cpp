class Solution {
public:
   int dp[2][2001] = {};
int maxSum(vector<int>& nums, int k, int m) {
    vector<int> ps{0};
    partial_sum(begin(nums), end(nums), back_inserter(ps));
    int res, best;
    for (int l = 1; l <= k; ++l) {
        res = best = INT_MIN;
        for (int i = l * m - 1; i < nums.size(); ++i) {
            best = max(best, dp[!(l % 2)][i - m + 1]);
            dp[l % 2][i + 1] = ps[i + 1] - ps[i - m + 1] + best;
            if (i >= l * m)
                dp[l % 2][i + 1] = max(dp[l % 2][i + 1], nums[i] + dp[l % 2][i]);
            res = max(res, dp[l % 2][i + 1]);
        }
    }
    return res;
}     
};
