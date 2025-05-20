class Solution {
public:
    void dfs(int u, int par, int lvl, int wt, vector<int> &levels, vector<int> &weights, vector<vector<pair<int, int>>> &graph, vector<vector<int>> &LCA) {
        levels[u] = lvl;
        weights[u] = wt;
        LCA[u][0] = par;

        for(auto &[v, w]: graph[u]) {
            if(v != par) {
                dfs(v, u, lvl + 1, wt + w, levels, weights, graph, LCA);
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

    int getDistance(int u, int v, int maxN, vector<int> &levels, vector<int> &weights, vector<vector<int>> &LCA) {
        int lca = findLCA(u, v, maxN, levels, LCA);
        return weights[u] + weights[v] - 2 * weights[lca];
    }
    
    vector<int> minimumWeight(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        int n = edges.size() + 1, m = queries.size();

        vector<vector<pair<int, int>>> graph(n);
        for(auto &edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        int maxN = log2(n);
        vector<int> levels(n);
        vector<int> weights(n);
        vector<vector<int>> LCA(n, vector<int> (maxN + 1, -1));
        
        dfs(0, -1, 0, 0, levels, weights, graph, LCA);
        init(n, maxN, LCA);

        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int src1 = queries[i][0], src2 = queries[i][1], dest = queries[i][2];
            
            int total = (getDistance(src1, dest, maxN, levels, weights, LCA) + 
                        getDistance(src2, dest, maxN, levels, weights, LCA) + 
                        getDistance(src1, src2, maxN, levels, weights, LCA)) / 2;
            ans[i] = total;
        }
        
        return ans;
    }
};
