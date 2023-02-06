class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<int> cnt(m+n, 0);
        vector<vector<bool>> vis1(m+2, vector<bool>(n+2, false));
        vector<vector<bool>> vis2(m+2, vector<bool>(n+2, false));
        vis1[0][1] = true, vis2[m+1][n] = true;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                vis1[i][j] = a[i-1][j-1] && (vis1[i-1][j] || vis1[i][j-1]);
            }
        }
        for (int i = m; i >= 1; --i) {
            for (int j = n; j >= 1; --j) {
                vis2[i][j] = a[i-1][j-1] && (vis2[i+1][j] || vis2[i][j+1]);
                cnt[i+j-2] += vis1[i][j] && vis2[i][j];
            }
        }
        for (int i = 1; i < m+n-2; ++i) {
            if (cnt[i] <= 1) return true;
        }
        return false;
    }
};
