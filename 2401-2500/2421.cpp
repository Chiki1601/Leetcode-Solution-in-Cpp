struct DSU {
    vector<int> size;
    vector<int> par;
    
    DSU (int n) {
        size.resize(n, 1);
        par.resize(n);
        for (int j = 0; j < n; j ++) par[j] = j;
    }
    
    int Leader (int x) {
        if (x == par[x]) return x;
        return (par[x] = Leader(par[x]));
    }
    
    void merge (int x, int y) {
        x = Leader(x);
        y = Leader(y);
        if (x == y) return;
        if (size[x] > size[y]) swap (x, y);
        
        size[y] += size[x];
        par[x] = y;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (auto i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        
        map<int, vector<int>> val_to_nodes;
        for (int j = 0; j < n; j ++) val_to_nodes[vals[j]].push_back(j);
        
        DSU dsu(n);
        int result = n;
        vector<bool> is_active(n);
        
        for (auto [_, indexes] : val_to_nodes) {
            for (auto i : indexes) {
                for (auto child: g[i]) {
                    if (is_active[child]) dsu.merge (i, child);
                }
                is_active[i] = true;
            }
            
            vector<int> leaders;
            for (auto i : indexes) leaders.push_back(dsu.Leader(i));
            sort (leaders.begin(), leaders.end());
                        
            int sz = leaders.size();
            for (int j = 0; j < sz; j ++) {
                long long cnt = 0;
                int cur = leaders[j];
                
                while (j < sz && leaders[j] == cur) j ++, cnt ++;
                j --;
                
                result += (cnt * (cnt - 1))/2;
            }
        }
        
        return result;
    }
};
