class Solution {
public:
    using ll = long long;
    int n;

    const ll INF = 1e18;
    vector<vector<pair<int, ll>>> normalAdj, taxAdj;

    vector<ll> dijkstra(int src, vector<vector<pair<int, ll>>>& adj) {
        vector<ll> dist(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if(d > dist[u]) 
                continue;

            for(auto [v, w] : adj[u]) {
                ll nd = d + w;

                if(nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int _n, vector<int>& prices, vector<vector<int>>& roads) {
        n = _n, normalAdj.assign(n, {}), taxAdj.assign(n, {});

        for(auto &r : roads) {
            int u = r[0], v = r[1], cost = r[2], tax = r[3];

            normalAdj[u].push_back({v, cost});
            normalAdj[v].push_back({u, cost});

            taxAdj[u].push_back({v, 1LL * cost * tax});
            taxAdj[v].push_back({u, 1LL * cost * tax});
        }

        vector<vector<ll>> distNormal(n);
        vector<vector<ll>> distTax(n);

        for(int i = 0; i < n; i++) {
            distNormal[i] = dijkstra(i, normalAdj);
            distTax[i] = dijkstra(i, taxAdj);
        }

        vector<int> res(n);

        for(int i = 0; i < n; i++) {
            res[i] = prices[i];

            for(int j = 0; j < n; j++) {
                ll cost = distNormal[i][j] + distTax[j][i] + prices[j];

                if(cost < res[i])
                   res[i] = (int)cost;
            }
        }

        return res;
    }
};
