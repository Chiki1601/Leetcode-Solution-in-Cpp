
class Solution {
public:
    vector<long long> redCost, blueCost, sz;
    string color;
    vector<vector<long long>> adj;

    void dfs(long long u, long long p) {
        sz[u] = 1;
        long long minRedSum = 0;
        long long blueSum = 0;

        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];  // Calculate subtree size
            blueSum += blueCost[v];  // Cost if each child subtree is made Blue
            minRedSum += min(redCost[v], blueCost[v]);  // Minimum cost for each child subtree
        }

        redCost[u] = (color[u]=='B' ? sz[u] : 0ll) + minRedSum;  // add cost if u is Red
        blueCost[u] = (color[u]=='R' ? sz[u] : 0ll) + blueSum;  // add cost if u is Blue
    }

    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        adj.assign(n, vector<long long>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        color = colors;
        redCost.assign(n, 0);
        blueCost.assign(n, 0);
        sz.assign(n, 0);

        dfs(0, -1);

        long long ans = blueCost[0];  // Make the entire tree Blue

        for (long long i = 0; i < n; i++) {
            //keep red component with topmost red vertex is i
            long long currCost = blueCost[0] - blueCost[i] + redCost[i];
            ans = min(ans, currCost);
        }

        return ans;
    }
};
