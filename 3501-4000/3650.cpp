class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const int INF = INT_MAX / 2;
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1], cost = edge[2];
            graph[from].push_back({to, cost});
            graph[to].push_back({from, cost * 2});
        }
        
        vector<int> d(n, INF);
        d[0] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            auto [distance, from] = q.top();
            q.pop();
            if (distance > d[from]) continue;
            
            for (auto [to, cost] : graph[from]) {
                if (d[to] > d[from] + cost) {
                    d[to] = d[from] + cost;
                    q.push({d[to], to});
                }
            }
        }
        
        return d[n - 1] == INF ? -1 : d[n - 1];
    }
};
