class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    int n;

    bool bfs(int node) {

        vector<char> color(n, -1);

        queue<pair<int, char>> q;

        q.push({node, 0});
        color[node] = 0;
        vis[node] = 1;

        while (!q.empty()) {
            auto [x, c] = q.front();
            q.pop();

            int next_color = 1 - c;

            for (auto it : adj[x]) {
                if (vis[it]) {
                    if (color[it] != next_color) {
                        return false;
                    }
                } else {
                    vis[it] = 1;
                    color[it] = next_color;
                    q.push({it, color[it]});
                }
            }
        }

        return true;
    }
    int maxPartitionFactor(vector<vector<int>>& points) {

        this->n = points.size();

        int l = 0;
        int r = 1e9;

        auto dist = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) +
                   abs(points[i][1] - points[j][1]);
        };

        auto even_cycle_check = [&]() {
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    if (bfs(i) == false) {
                        return false;
                    }
                }
            }

            return true;
        };

        auto check = [&](int mini) {
            adj.assign(n, {});
            vis.assign(n, 0);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (dist(i, j) < mini) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }

            return even_cycle_check();
        };

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            bool flag = check(mid);
            if (flag) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return (r >= 1e9 ? 0 : r);
    }
};
