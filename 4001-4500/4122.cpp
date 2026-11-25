class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int, long long>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], static_cast<long long>(edge[2])});
        }

        vector<long long> ans(n, -1LL);
        vector<unordered_set<int>> seen(n);
        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0LL, -1, 0});

        while (!pq.empty()) {
            auto [t, u, v] = pq.top();
            pq.pop();

            if (ans[v] != -1LL) {
                continue;
            }
            if (u != -1) {
                seen[v].insert(u);
            }
            if (v == 0 || static_cast<int>(seen[v].size()) >= requiredSignals[v]) {
                ans[v] = t;
                for (const auto& [nxt, d] : adj[v]) {
                    if (ans[nxt] == -1LL) {
                        pq.push({t + d, v, nxt});
                    }
                }
            }
        }

        return ans;
    }
};
