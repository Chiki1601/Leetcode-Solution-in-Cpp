class Solution {
public:
   
vector<vector<int>> buildGraph(vector<vector<int>>& edges){
    vector<vector<int>> g(edges.size() +1 );
    for(auto e: edges){
        g[e[0]].push_back(e[1]);  g[e[1]].push_back(e[0]);
    }
    return g;
}

int dfs(vector<vector<int>>& g, int root, int par, int k, int count = 1){
    if(k < 0) return 0;
    for(auto node: g[root]) count += (node != par)?dfs(g, node, root, k-1): 0;
    return count; 
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    auto g1 = buildGraph(edges1), g2 = buildGraph(edges2);
    int count = 0, n = edges1.size()+1, m = edges2.size()+1;
    vector<int> ans;
    for(int i = 0; i < m; ++i) count = max(count, dfs(g2, i, -1, k-1));
    for(int i = 0; i < n; ++i) ans.push_back(count + dfs(g1, i, -1, k));
    return ans;
}
};
