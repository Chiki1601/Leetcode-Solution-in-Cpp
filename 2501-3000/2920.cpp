class Solution {
public:
    int dp[100005][14];
    int find(unordered_map<int,vector<int>>&graph,int source,int parent, vector<int>&coins,int k,int type){
        int ans=0;
        if(dp[source][type]!=-1)return dp[source][type];

        //Value of the node is determined by dividing it 2^(Number of second routes taken)
        int val = coins[source]/(1<<type);

        //pick1 denotes the first route
        int pick1 = val-k;

        //pick2 denotes the second route
        int pick2 = floor(val/2.0);

        for(auto it:graph[source]){
            if(parent==it)continue;
            pick1 +=find(graph,it,source,coins,k,type);


            if(type<13) // No need to increment beyond 14 because 10^4/2^14 =0. So anything beyond that will be zero
            pick2 +=find(graph,it,source,coins,k,type+1);
        }
        return dp[source][type] = max(pick1,pick2);
    }
        
        
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        memset(dp,-1,sizeof(dp));
        unordered_map<int,vector<int>>graph;
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        return find(graph,0,-1,coins,k,0);
    }
};
