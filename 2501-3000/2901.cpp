class Solution {
public:
    vector<string> res;
    
    void dfs(int i, int level, vector<vector<int>> &adj, vector<int> &vis, vector<string> &curr, vector<string>& words){
    
        if(vis[i] >= level){
            return;
        }
        
        vis[i] = level;
        
        curr.push_back(words[i]);

        
        
        if(adj[i].size() == 0 && res.size() < curr.size()){
            res = curr;
        }
        
        for(int k : adj[i]){
            dfs(k, level + 1, adj, vis, curr, words);
        }
        
        curr.pop_back(); 
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<vector<int>> adj(n);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(words[i].size() == words[j].size() && groups[i] != groups[j]){
                    int c = 0;
                    for(int k = 0 ; k < words[j].size() ; k++){
                        if(words[i][k] != words[j][k])
                            c++;
                    }
                    if(c == 1)
                        adj[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(n, -1);
        
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == -1){
                vector<string> curr;
                dfs(i, 0, adj, vis, curr, words);
            }
        }
        
        return res;
    }
};
