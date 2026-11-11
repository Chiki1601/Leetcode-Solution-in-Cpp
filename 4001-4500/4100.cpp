using ll = long long;
const ll INF = 1e18;

class Solution {
public:
    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
        ll ans = INF;
        int n = values.size();
        vector<ll> best(n, INF);

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            ll w = e[2];
            int pu = __builtin_parity(values[u]);
            int pv = __builtin_parity(values[v]);

            if (pu == pv) {
                ans = min(ans, w);
            } else {
                int zero_node = (pu == 0) ? u : v;
                ans = min(ans, best[zero_node] + w);
                best[zero_node] = min(best[zero_node], w);
            }
        }

        return ans >= INF ? -1 : ans;
    }
};
