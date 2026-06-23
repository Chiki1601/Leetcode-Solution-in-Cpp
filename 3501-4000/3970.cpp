class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>>dist(n,vector<long long>(k+1,LLONG_MAX));
       priority_queue<
               vector<long long>,
               vector<vector<long long>>,
        greater<vector<long long>>>pq;
        dist[0][k]=0;
        pq.push({0,0,k});

        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            int d=i[0],u=i[1],rem=i[2];
            if(d>dist[u][rem])continue;
            for(auto& it:adj[u]){
                int v=it.first,w=it.second;
                if(labels[u]==labels[v]){
                    if(rem<=1)continue;
                    int nrem=rem-1;
                    if(dist[v][nrem]>d+w){
                        dist[v][nrem]=d+w;
                        pq.push({dist[v][nrem],v,nrem});
                    }
                }
                else{
                    if(dist[v][k]>d+w){
                        dist[v][k]=d+w;
                        pq.push({dist[v][k],v,k});
                    }
                }
            }
        }
        long long ans=LLONG_MAX;
        for(int rem=1;rem<=k;rem++){
            ans=min(ans,dist[n-1][rem]);
        }
        return ans==LLONG_MAX?-1:(int)ans;
    }
};
