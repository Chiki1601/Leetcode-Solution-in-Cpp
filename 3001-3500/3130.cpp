class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[zero+1][one+1][2];
        int mod = 1000000007;
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                dp[i][j][0] = dp[i][j][1] = 0;
                if (i == 0 || j == 0) {
                    if (0 < i && i <= limit) dp[i][j][0] = 1;
                    if (0 < j && j <= limit) dp[i][j][1] = 1;
                    continue;
                }
                if (i-1 >= 0) dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                if (i-1-limit >= 0) dp[i][j][0] = (dp[i][j][0] + mod - dp[i-1-limit][j][1]) % mod;
                if (j-1 >= 0) dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % mod;
                if (j-1-limit >= 0) dp[i][j][1] = (dp[i][j][1] + mod - dp[i][j-1-limit][0]) % mod;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};
