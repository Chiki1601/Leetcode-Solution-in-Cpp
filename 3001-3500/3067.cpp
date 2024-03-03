class Solution {
public:
      int dfs(int root, int par, int dist, vector<vector<pair<int, int>>>& graph, int& signalSpeed){
        int count = (dist % signalSpeed)?0:1;       // check if the current node is valid or not
        for(auto [n, w]: graph[root]){              
            if(n != par) count += dfs(n, root, dist + w, graph, signalSpeed);
        }
        return count;
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        vector<vector<pair<int, int>>> graph(edges.size() + 1);
        for(auto e: edges){                        // create graph from the edges
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> ans;
        for(int i = 0; i <= edges.size(); ++i){    // iterate over 0 to n and consider each node as the root node
            int nodeCount = 0, res = 0;
            for(auto [n, w]: graph[i]){            // for each root node, iterate over its child subtree and find the valid node count from each sub tree
                int t = dfs(n, i, w, graph, signalSpeed);
                res += nodeCount * t;  nodeCount += t;    // keep accumulating answer by multiplying the current sub tree valid node count with the previously seen node count
            }
            ans.push_back(res);
        }
        return ans;
    }
};
