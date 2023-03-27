class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size(); 
        vector<unordered_set<int>> tree(n); 
        for (auto& e : edges) {
            tree[e[0]].insert(e[1]); 
            tree[e[1]].insert(e[0]); 
        }
        queue<int> leaf; 
        for (int i = 0; i < n; ++i) {
            int u = i; 
            while (tree[u].size() == 1 && coins[u] == 0) {
                int v = *tree[u].begin(); 
                tree[u].erase(v); 
                tree[v].erase(u); 
                u = v; 
            }
            if (tree[u].size() == 1) leaf.push(u); 
        }
        for (int j = 0; j < 2; ++j) {
            for (int sz = leaf.size(); sz; --sz) {
                int u = leaf.front(); leaf.pop(); 
                if (tree[u].size()) {
                    int v = *tree[u].begin(); 
                    tree[u].erase(v); 
                    tree[v].erase(u); 
                    if (tree[v].size() == 1) leaf.push(v); 
                }
            }
        }
        int ans = 0; 
        for (int i = 0; i < n; ++i) ans += tree[i].size(); 
        return ans; 
    }
};
