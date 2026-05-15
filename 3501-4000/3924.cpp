class Solution {
public:
    bool helper(vector<pair<int,int>> adj[],int n,int s,int t,int thresh,int k){
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        dist[s]=0;
        while(!pq.empty()){
            int currc=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(currc>dist[u]){
                continue;
            }
            for(auto a:adj[u]){
                int v=a.first;
                int c=a.second;
                int ac=0;
                if(c>thresh){
                    ac=1;
                }
                if(dist[v]>(currc+ac)){
                    dist[v]=(currc+ac);
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[t]<=k){
            return true;
        }
        return false;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int i=0;
        int j=1e9;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(helper(adj,n,source,target,mid,k)){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};
