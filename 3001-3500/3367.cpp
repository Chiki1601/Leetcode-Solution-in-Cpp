class Solution { 
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int K) {
        int n = edges.size() + 1; // Total number of nodes in the tree
        vector<int> e[n], v[n];   // e[i] stores adjacent nodes, v[i] stores edge weights
        for (auto &edge : edges) {
            e[edge[0]].push_back(edge[1]);
            v[edge[0]].push_back(edge[2]);
            e[edge[1]].push_back(edge[0]);
            v[edge[1]].push_back(edge[2]);
        }

        long long f[n][2]; // DP table: f[i][0] - max sum without the edge, f[i][1] - max sum with the edge
        auto dfs = [&](auto &&self, int sn, int fa, int from) -> void {
            vector<long long> vec;
            long long base = 0;

            // Traverse all adjacent nodes (children)
            for (int i = 0; i < e[sn].size(); i++) {
                int fn = e[sn][i];
                if (fn == fa) continue; // Skip the parent node
                self(self, fn, sn, v[sn][i]); // Recursive DFS
                base += f[fn][0];             // Sum up the maximum values without the edge to each child
                vec.push_back(f[fn][1] - f[fn][0]); // Store the difference between including or excluding an edge
            }

            // Sort the differences in descending order to maximize the sum
            sort(vec.begin(), vec.end(), greater<long long>());
            long long sm = 0;
            // Add the best `K-1` contributions from the children
            for (int i = 0; i < K - 1 && i < vec.size(); i++) if (vec[i] > 0) sm += vec[i];
            f[sn][1] = base + sm + from; // Max sum if the edge is included

            // Include the `K`-th best edge if beneficial
            if (vec.size() >= K && vec[K - 1] > 0) sm += vec[K - 1];
            f[sn][0] = base + sm; // Max sum without the edge
        };

        dfs(dfs, 0, -1, 0); // Start DFS from node 0
        return f[0][0]; // Return the maximum sum of edges
    }
};
