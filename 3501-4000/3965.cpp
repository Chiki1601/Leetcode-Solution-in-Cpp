class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>temp;
        stack<int>st;st.push(0);
        while(!st.empty()){
            int u=st.top();st.pop();
            temp.push_back(u);
            for(int v:adj[u])st.push(v);
        }
        vector<long long>ft(n,0);

        for(int idx=temp.size()-1;idx>=0;idx--){
            int u=temp[idx];
            if(adj[u].size()==0)ft[u]=baseTime[u];
            else{
                long long mini=LLONG_MAX,maxi=0;
                for(int v:adj[u]){
                    long long f=ft[v];
                    mini=min(mini,f);
                    maxi=max(maxi,f);
                }
                 long long own=(maxi-mini)+baseTime[u];
             ft[u]=own+maxi;
            }
        }
       return ft[0]; 
    }
};
