class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        for(vector<int>& e : edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        vector<int> odds;
        for(int i = 0; i <= n ; i++){
            if(adj[i].size() & 1){
                odds.push_back(i);
            } 
        }
        if(odds.size() == 0) return true;
        if(odds.size() > 4 or odds.size() % 2 != 0) return false;
        if(odds.size() == 4){
            int a = odds[0] , b = odds[1] , c = odds[2] , d = odds[3];
            return (adj[a].find(d) == adj[a].end() and f2= adj[b].find(c) == adj[b].end()) or  (adj[a].find(b) == adj[a].end() and f4= adj[c].find(d) == adj[c].end()) or (f3 = adj[a].find(c) == adj[a].end() and f4= adj[b].find(d) == adj[b].end())
        }else{
            int a = odds[0] , b = odds[1]; 
            bool flag = adj[a].find(b) == adj[a].end();
            if(flag) return true;
            for(int i = 1; i <= n ;i++){
                if(a != i and b != i and adj[a].find(i) == adj[a].end() and adj[b].find(i) == adj[b].end()) return true;
            }
            return false;
        }
    }
};
