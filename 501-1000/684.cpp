class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n=edges.size();
        UnionFind G(n+1);
        for(auto& e: edges)
            if (!G.Union(e[0], e[1])) return e;
        return {};
    }
};
