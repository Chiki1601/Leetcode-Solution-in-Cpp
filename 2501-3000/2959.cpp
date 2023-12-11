class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        // Iterate through all subsets of nodes (1 << n) using bitmasking
        for(int i = 0; i < 1 << n; i++) {
            // Create an adjacency matrix to represent the graph
            vector<vector<int>> g(n, vector<int>(n, 1e9));

            // Update the graph based on the selected nodes in the subset
            for(auto &it : roads) {
                int x = it[0], y = it[1], w = it[2];
                if((i >> x & 1) && (i >> y & 1)) {
                    g[x][y] = min(g[x][y], w);
                    g[y][x] = min(g[y][x], w);
                }
            }

            // Set diagonal elements to 0
            for(int j = 0; j < n; j++)
                g[j][j] = 0;

            // Floyd-Warshall algorithm for finding the shortest paths
            for(int p = 0; p < n; p++) {
                for(int q = 0; q < n; q++) {
                    for(int k = 0; k < n; k++) {
                        g[q][k] = min(g[q][k], g[q][p] + g[p][k]);
                    }
                }
            }

            // Check if the selected nodes in the subset form a valid set
            int ok = 1;
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if((i >> j & 1) && (i >> k & 1)) {
                        ok &= (g[j][k] <= maxDistance);
                    }
                }
            }

            // Increment the answer if the subset forms a valid set
            ans += ok;
        }
        return ans;
    }
};

