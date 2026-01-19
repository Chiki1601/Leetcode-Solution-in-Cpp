class Solution {
public:
    void dfs(int x, int p, vector<vector<pair<int, int>>> &adj, string &prsnt, 
        string &target, vector<int> &visited){
        for(auto &y:adj[x]){
            if(y.first==p) continue;
            dfs(y.first, x, adj, prsnt, target, visited);

            if(prsnt[y.first] != target[y.first]){
                prsnt[y.first] = (prsnt[y.first]=='0') ? '1' : '0';
                prsnt[x] = (prsnt[x]=='0') ? '1' : '0';
                visited[y.second]^=1;
            }
        }
    }
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<int> arr;
        vector<vector<pair<int, int>>> adj(n);
        int i=0;
        for(auto &x:edges){
            adj[x[0]].push_back({x[1], i});
            adj[x[1]].push_back({x[0], i});
            i++;
        }
        int x=0, y=0;
        for(int i=0;i<n;i++){
            if(start[i]=='1') x++;
            if(target[i]=='1') y++;
        }

        if(x%2 != y%2)return {-1};

        string prsnt=start;
        vector<int> visited(n-1, 0);
        dfs(0, -1, adj, prsnt, target, visited);
        for(int i=0;i<n-1;i++){
            if(visited[i])
                arr.push_back(i);
        }

        return arr;
    }
};
