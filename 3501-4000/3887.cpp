class DSU {
private:
    vector<pair<int,int>> p;
    int c;

public:
    DSU(int n) {
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) p[i] = {i, 0};
        c = n;
    }

    pair<int,int> find(int i) {
        if(p[i].first == i) return p[i];
        auto [node, xr] = find(p[i].first);
        p[i] = {node, xr ^ p[i].second};
        return p[i];
    }

    bool unite(int i, int j, int value) {
        auto [root_i, i_xr] = find(i);
        auto [root_j, j_xr] = find(j);
        
        if (root_i != root_j) {
            p[root_i] = { root_j, i_xr ^ j_xr ^ value };
            c--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        DSU d(n);
        int cnt = 0;
        
        for(auto x: edges){
            int u = x[0], v = x[1], w = x[2];
            
            if(!d.unite(u, v, w)){
                auto [_, xr1] = d.find(u);
                auto [_, xr2] = d.find(v);
                if((xr1 ^ xr2) == w) cnt++;
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
