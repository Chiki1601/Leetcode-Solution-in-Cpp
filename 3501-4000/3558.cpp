const int MOD = 1e9 + 7;

class Solution {
public:
    int maxDepth = 0;
    void dfs(int node, int par, int depth, vector<vector<int>> &graph) {
        maxDepth = max(maxDepth, depth);
        for (auto &x: graph[node]) {
            if (x != par) {
                dfs(x, node, depth + 1, graph);
            }
        }
    }

    long long powerMod(long long x, long long y, int mod) {
        long long result = 1;
        while (y > 0) {
            if (y % 2) {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            y /= 2;
        }
        return result;
    }
    
    int assignEdgeWeights(vector<vector<int>> &edges) {
        int n = edges.size();
        
        vector<vector<int>> graph(n + 2);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    
        maxDepth = 0;
        dfs(1, -1, 0, graph);
        return powerMod(2, maxDepth - 1, MOD);
    }
};
