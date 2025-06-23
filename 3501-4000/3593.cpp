typedef long long ll;
class Solution {
public:
    void dfs1(int u,int p,vector<vector<int>>&adj,vector<int>&cost,vector<ll> &sum){
        for(auto v:adj[u]){
            if(v==p)continue;
            sum[v]=sum[u]+cost[v];
            dfs1(v,u,adj,cost,sum);
        } 
    }

    ll dfs2(int u,int p,vector<vector<int>>&adj,vector<ll> &sum,ll target,vector<int>&arr){
        bool isLeaf=true;
        ll mini=LLONG_MAX;
        for(int v:adj[u]){
            if(v==p)continue;
                isLeaf=false;
                mini=min(mini,dfs2(v,u,adj,sum,target,arr));
        }
        if(isLeaf){
            mini=target-sum[u];
        }
        return arr[u]=mini;
    }

    void dfs3(int u,int p,vector<vector<int>>&adj,vector<int>&arr,int &ans){
        ll parent=0;
        if(p==-1){
            parent=0LL;
        }
        else{
            parent=arr[p];
        }
        if(arr[u]>parent){
            ans++;
        }
        for(auto it:adj[u]){
            if(it==p){
                continue;
            }
            dfs3(it,u,adj,arr,ans);
        }
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<ll>sum(n);
        sum[0]=cost[0];
        dfs1(0,-1,adj,cost,sum);

        ll target=LLONG_MIN;
        for(int u=0;u<n;u++){
            bool leaf= (u==0 ? adj[u].empty() : adj[u].size()==1);
            if(leaf)
                target=max(target,sum[u]);
        }

        vector<int>arr(n,0);
        int ans=0;
        dfs2(0,-1,adj,sum,target,arr);
        dfs3(0,-1,adj,arr,ans);

        return ans;
    }
};
