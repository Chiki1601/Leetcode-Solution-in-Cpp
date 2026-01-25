class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto bfs = [&](int node) -> vector<int> {
            vector<int> dist(n, -1);
            dist[node] = 0;

            deque<int> queue;
            queue.push_back(node);
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop_front();
                for (int v : adj[u]) {
                    // Check if this neighbour was not visited yet
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        queue.push_back(v);
                    }
                }
            }
            return dist;
        };

        // Calculate distances from every node to x, y and z
        vector<int> dx = bfs(x), dy = bfs(y), dz = bfs(z);

        int result = 0;
        for (int i = 0; i < n; ++i) {
            long long a = dx[i], b = dy[i], c = dz[i];

            // Ensure a <= b <= c
            if (a > b) { long long t = a; a = b; b = t; }
            if (b > c) { long long t = b; b = c; c = t; }
            if (a > b) { long long t = a; a = b; b = t; }

            result += int(a * a + b * b == c * c);
        }

        return result;
    }
};
