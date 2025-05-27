class Solution {
public:
    bool isConsec(char a, char b) {
        return abs(a - b) == 1 || abs(a - b) == 25;
    }

    string lexicographicallySmallestString(string s) {
        int n = s.size();
        vector<vector<string>> dp(n + 1, vector<string>(n + 1, ""));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len;

                // Base: Keep s[i]
                string res = s[i] + dp[i + 1][j];

                // Try to remove s[i] and s[k] if possible
                for (int k = i + 1; k < j; k++) {
                    if (isConsec(s[i], s[k]) && dp[i + 1][k] == "") {
                        res = min(res, dp[k + 1][j]);
                    }
                }

                dp[i][j] = res;
            }
        }

        return dp[0][n];
    }
};
