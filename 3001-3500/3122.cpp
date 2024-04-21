class Solution {
public:
   int cnt[1000][10] = {}, dp[1000][10] = {};
int dfs(int i, int p, int m, int n) {
    if (i == n)
        return 0;
    if (dp[i][p] == 0)
        for (int v = 0; v < 10; ++v)
            if (i == 0 || v != p)
                dp[i][p] = max(dp[i][p], cnt[i][v] + dfs(i + 1, v, m, n));
    return dp[i][p];
}
int minimumOperations(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            ++cnt[j][g[i][j]];
    return m * n - dfs(0, 0, m, n);
}
};
