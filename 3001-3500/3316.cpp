class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int m = source.size(), n = pattern.size();
        unordered_set<int> target(targetIndices.begin(), targetIndices.end());

        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j <= n; ++j) {
                dp[j] += target.count(i);
                if (j < n && source[i] == pattern[j]) {
                    dp[j] = max(dp[j], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};
