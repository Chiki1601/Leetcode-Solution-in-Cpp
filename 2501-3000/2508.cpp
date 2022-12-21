class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        vector<int> deg(n);
        for(auto edge:edges) {
            graph[edge[0] - 1].insert(edge[1] - 1);
            graph[edge[1] - 1].insert(edge[0] - 1);
            deg[edge[0]-1]++;
            deg[edge[1]-1]++;
        }
        vector<int> nodes;
        for(int i = 0; i < n; i += 1) {
            if(deg[i]&1) nodes.push_back(i);
        }
        if(nodes.size() == 0) return true;
        if(nodes.size() % 2 == 1 || nodes.size() > 4) return false;
        if(nodes.size() == 2) {
            if(!graph[nodes[0]].count(nodes[1])) return true;
            unordered_set<int> st;
            for(auto it: graph[nodes[0]]) st.insert(it);
            for(auto it:graph[nodes[1]]) st.insert(it);
            if(st.size() == n) return false;
            return true;
        }
        bool flag = false;
        int maxcnt = 0;
        vector<int> u2;
        for(int x: nodes) {
            int cnt = 0;
            vector<int> e;
            for(int y:nodes){
                if(graph[x].count(y)) {
                    cnt++;
                    e.push_back(y);
                    flag = true;
                }
            }
            if(cnt > maxcnt) {
                u2 = e;
                maxcnt = cnt;
            }
        }
        if(!flag || maxcnt == 1) return true;
        if(maxcnt == 3) return false;
        if(graph[u2[0]].count(u2[1])) return false;
        return true;
    }
};
