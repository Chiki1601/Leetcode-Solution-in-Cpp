const int MOD = 1e9 + 7;

class Solution {
public:
    void dfs(int u, int par, int lvl, vector<int> &levels, vector<vector<int>> &graph, vector<vector<int>> &LCA) {
        levels[u] = lvl;
        LCA[u][0] = par;

        for(auto &v: graph[u]) {
            if(v != par) {
                dfs(v, u, lvl + 1, levels, graph, LCA);
            }
        }
    }

    void init(int n, int maxN, vector<vector<int>> &LCA) {
        for(int i = 1; i <= maxN; i++) {
            for(int j = 0; j < n; j++) {
                if(LCA[j][i - 1] != -1) {
                    int par = LCA[j][i - 1];
                    LCA[j][i] = LCA[par][i - 1];
                }
            }
        }
    }

    int findLCA(int a, int b, int maxN, vector<int> &levels, vector<vector<int>> &LCA) {
        if(levels[a] > levels[b]) swap(a, b);

        int d = levels[b] - levels[a];
        while(d > 0) {
            int jump = log2(d);
            b = LCA[b][jump];
            d -= (1LL << jump);
        }

        if(a == b) return a;

        for(int i = maxN; i >= 0; i--) {
            if(LCA[a][i] != -1 && LCA[a][i] != LCA[b][i]) {
                a = LCA[a][i], b = LCA[b][i];
            }
        }

        return LCA[a][0];
    }

    int getDistance(int u, int v, int maxN, vector<int> &levels, vector<vector<int>> &LCA) {
        int lca = findLCA(u, v, maxN, levels, LCA);
        return levels[u] + levels[v] - 2 * levels[lca];
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
    
    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        int n = edges.size() + 1, m = queries.size();

        vector<vector<int>> graph(n);
        for(auto &edge: edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        int maxN = log2(n);
        vector<int> levels(n);
        vector<vector<int>> LCA(n, vector<int> (maxN + 1, -1));
        
        dfs(0, -1, 0, levels, graph, LCA);
        init(n, maxN, LCA);     

        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int u = queries[i][0] - 1, v = queries[i][1] - 1;
            int dist = getDistance(u, v, maxN, levels, LCA);

            if(dist == 0) {
                ans[i] = 0;
                continue;
            }
            
            ans[i] = powerMod(2, dist - 1, MOD);
        }
        
        return ans;
    }
};
