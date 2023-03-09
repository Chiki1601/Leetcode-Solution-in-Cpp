class Solution {
public:
    //used to hash edges
    map<pair<int, int>, bool> mp;

    //get answer for node 0
    int get_ans(unordered_map<int, list<int>>& adj, int src, vector<bool>& vis){
        vis[src] = 1;
        int ans = 0;
        for(auto i: adj[src]){
            if(!vis[i]){
                ans += (mp.count({src, i}) + get_ans(adj, i, vis));
            }
        }
        return ans;
    }
    //stores the number of nodes where edges in guesses >= k
    int anss = 0;
    
    void dfs(unordered_map<int, list<int>>& adj, vector<bool>& vis, int k, int src, int ans){
        if(ans >= k) anss++;
        vis[src] = 1;
        for(auto i: adj[src]){
            if(!vis[i]){
                dfs(adj, vis, k, i, ans - mp.count({src, i}) + mp.count({i, src}));
            }
        }
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        unordered_map<int, list<int>> adj;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(auto i: guesses){
            mp[{i[0], i[1]}] = 1;
        }
        int n = edges.size()+1;
        vector<bool> vis(n, 0);
        int ans = get_ans(adj, 0, vis);
        fill(vis.begin(), vis.end(), 0);
        dfs(adj, vis, k, 0, ans);
        return anss;
    }
};
