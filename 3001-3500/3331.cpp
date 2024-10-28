class Solution {
public:
    //TC:O(N * H); SC:O(N^2); H:Height of tree
    vector<pair<int, int>> change; //{node, new_parent} Used to record the rearranged of edges
    vector<int> adj[100000];  // Adjacency list for the tree
    
    void dfs(int node, int original, vector<int>& parent, string& s) { //Traverse upwards from original to node 0
        if (s[original] == s[node]){
            change.push_back({original, node}); //node is the new parent of orginal
            return;
        }
    
        if (node == 0) return;
    
        dfs(parent[node], original, parent, s);
    }
    
    void countChildren(int i, vector<int>& ans) { //Counts no. of children of node i
        for (auto child : adj[i]) {
            countChildren(child, ans);
            ans[i] += ans[child];
        }
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> res(n, 1);
    
        for (int i = 1; i < n; i++) {
            dfs(parent[i], i, parent, s); //for each node, find the ancestor whose character is assigned is same as that of i
        }
    
        for (auto itr : change) parent[itr.first] = itr.second; //Rearrange the edges
    
        for (int i = 1; i < n; i++){
            adj[parent[i]].push_back(i); //construct the new graph
        }
        
        countChildren(0, res);
        
        return res;
    }
};
