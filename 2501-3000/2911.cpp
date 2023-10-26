class Solution {
    int check(const string &s, int start, int d, int num) {
        int r = 0;
        for (int offset = 0; offset < d; ++offset) {
           for (int i = start + offset, j = i + d * (num - 1); i < j; i += d, j -= d) {
               r += s[i] != s[j];
           }
       }
       return r;
    }
    
    int cal(const string &s, int i, int j, vector<vector<int>> &v) {
        if (v[i][j] >= 0) return v[i][j];
        const int len = j - i + 1;
        if (len == 1) return v[i][j] = INT_MAX;
        v[i][j] = len - 1;
        for (int d = 1; d * d <= len; ++d) {
            if (len % d == 0) {
                const int num = len / d;
                v[i][j] = min(v[i][j], check(s, i, d, num));
                if (d != num && d != 1) {
                    v[i][j] = min(v[i][j], check(s, i, num, d));
                }
            }
        }
        return v[i][j];
    }
    
    int dfs(const string &s, int i, int k, vector<vector<int>> &dp, vector<vector<int>> &v) {
        const int n = s.length();
        if (i >= n) return k == 0 ? 0 : INT_MAX;
        if (dp[i][k] >= 0) return dp[i][k];
        if (n - i < k + k) return dp[i][k] = INT_MAX;
        if (k == 1) return dp[i][k] = cal(s, i, n - 1, v);
        if (k == 0) return dp[i][k] = INT_MAX;
        dp[i][k] = INT_MAX;
        for (int j = i; j < n; ++j) {
            const int temp = dfs(s, j + 1, k - 1, dp, v);
            if (temp < INT_MAX) {
                const int t = cal(s, i, j, v);
                if (t < INT_MAX) {
                    dp[i][k] = min(dp[i][k], temp + cal(s, i, j, v));
                }
            }
        }
        return dp[i][k];
        
    }
public:
    int minimumChanges(string s, int k) {
        const int n = s.length();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1)), v(n, vector<int>(n, -1));
        return dfs(s, 0, k, dp, v);
    }
};
