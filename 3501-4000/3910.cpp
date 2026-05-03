class Solution {
public:
    int isConnected(vector<vector<int> >& adj, int n, int hash, vector<int>& nums){
        vector<int> vis(n+1);
        queue<int> q;
        for(int i = 1; i < (1 << n); i = (i << 1)){
            if(hash & i){
                q.push(log2(i) + 1);
                break;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = 1;
            for(auto v: adj[u]){
                if(vis[v] || ((1 << (v-1) & hash) == 0)) continue;
                q.push(v);
            }
        }
        int ans = 0;
        for(int i = 1; i < (1 << n); i = (i << 1)){
            if(hash & i){
                if(!vis[log2(i) + 1]){
                    return 0;
                }
                ans += nums[log2(i)];
            }
        }
        if(ans % 2 == 0) return 1;
        return 0;
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int> > adj(n+1);
        for(auto it: edges){
            adj[it[0]+1].push_back(it[1]+1);
            adj[it[1]+1].push_back(it[0]+1);
        }
        
        int ans = 0;
        for(int i = 1; i < (1 << n); i++){
            ans += isConnected(adj, n, i, nums);
        }

        return ans;
    }
};
