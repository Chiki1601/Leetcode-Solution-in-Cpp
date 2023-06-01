class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        vector<int> r(m), c(n);
        unordered_map<int, vector<vector<int>>> vmap;
        vector<vector<int>> temp(m, vector<int>(n));
        set<int> s;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vmap[-mat[i][j]].push_back({i, j});
                s.insert(-mat[i][j]);
            }
            
        }
        for (int x : s) {
            for (const auto& v : vmap[x]) {
                temp[v[0]][v[1]] = max(r[v[0]], c[v[1]]) + 1;
            }
            for (const auto& v : vmap[x]) {
                r[v[0]] = max(r[v[0]], temp[v[0]][v[1]]);
                c[v[1]] = max(c[v[1]], temp[v[0]][v[1]]);
            }   
        }
        return max(*max_element(r.begin(), r.end()), *max_element(c.begin(), c.end()));
        
    }
};
     
