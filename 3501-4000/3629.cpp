class Solution {
public:
    vector<int>factor(int x){
        vector<int>res;
        for(int d=2;d*d<=x;d++){
            if(x%d==0){
                res.push_back(d);
                while(x%d==0)x/=d;
            }
        }
        if(x>1)res.push_back(x);
        return res;
    }
    int minJumps(vector<int>& nums) {
        unordered_map<int,vector<int>>adj;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int>temp=factor(nums[i]);
            for(int it:temp)adj[it].push_back(i);
        }

        vector<int>dist(n,INT_MAX);
        // vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,0});
        dist[0]=0;

        while(!q.empty()){
            auto [dis,node]=q.top();
            q.pop();

            if(node+1<n&&dist[node+1]>dis+1){
                dist[node+1]=1+dis;
                q.push({dist[node+1], node+1});
            }
            if(node-1>=0&&dist[node-1]>dis+1){
                dist[node-1]=1+dis;
                q.push({dist[node-1], node-1});
            }

            for(auto it:adj[nums[node]]){
                if( dist[it]>dis+1){
                    dist[it]=1+dis;
                    q.push({dist[it], it});
                }
            }
            adj[nums[node]].clear(); 
        }
        return dist[n-1];
    }
};
