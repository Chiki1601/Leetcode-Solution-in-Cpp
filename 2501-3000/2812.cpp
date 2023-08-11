using ppi = pair<pair<int, int>, int>;
class Solution {
public:

    bool isOk(vector<vector<int>>& grid, vector<vector<int>>&vis) {
        if (vis[0][0] == 1) return false;
        int n = grid.size();
        int v[] = { -1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            if (r == n - 1 && c == n - 1) return true;
            for (int i = 0; i < 4; i++) {
                int nr = r + v[i];
                int nc = c + v[i + 1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc] == 1)continue;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        return false;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int x) {
        queue<ppi> q;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, x-1});
                    vis[i][j] = 1;
                }
            }
        }
        if(x == 0) return;
        int v[] = { -1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int d = it.second;
            if (d == 0) continue;
            for (int i = 0; i < 4; i++) {
                int nr = r + v[i];
                int nc = c + v[i + 1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc] == 1)continue;
                vis[nr][nc] = 1;
                q.push({{nr, nc}, d - 1});
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int s = 0, e = n - 1;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            bfs(grid, vis, mid);
            if (isOk(grid, vis)) {
                ans = max(mid, ans);
                s = mid + 1;
            } else {
                e = mid - 1;

            }
        }
        return ans;
    }
};
