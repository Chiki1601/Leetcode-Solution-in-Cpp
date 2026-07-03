class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {

        vector<vector<pair<int, int>>> g(n);
        for (auto &e : edges) g[e[0]].push_back({e[1], e[2]});

        // Min-heap ordered by {time, -power, node}
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<>> q;

        // Tracks the highest power we've had when arriving at each node
        vector<int> mp(n, -1);

        q.push({0, -power, source});

        while(!q.empty()){

            auto [t, p, u] = q.top();
            q.pop();

            // Pruning: If we've been here before with equal or more power, drop it.
            if (-p <= mp[u]) continue;
            mp[u] = -p;

            // First time popping target guarantees minimum time with maximum power
            if (u == target) return{t, -p};

            // Check if we have enough power to pay the toll to leave
            if(-p < cost[u]) continue;

            for (auto & [v, w] : g[u]){
                q.push({t+w, (p + cost[u]), v});
            }
        }
        return{-1, -1};
    }

};
