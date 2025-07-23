typedef long long ll;
class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    ll dfs(vector<vector<int>>& grid, int r, int c, int m, int n, vector<vector<bool>>& vis, int k) {
        vis[r][c] = true;
        ll sum = grid[r][c];
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0 && !vis[nr][nc]) {
                sum += dfs(grid, nr, nc, m, n, vis, k);
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    ll land = dfs(grid, i, j, m, n, vis, k);
                    if (land % k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};
