class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if (n > 1 && k == 1) return -1;

        using State = tuple<double, int, int, int>; // (time, multiplier index, visited mask, return flag)
        priority_queue<State, vector<State>, greater<State>> pq;
        map<tuple<int, int, int>, double> dist;  // shortest time for each state

        int en = (1 << n) - 1;  // All bits set => all delivered

        // Precompute max delivery time per subset
        vector<int> mx(1 << n, 0);
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) mx[i] = max(mx[i], time[j]);
            }
        }

        pq.push({0.0, 0, 0, 0});  // Initial state
        dist[{0, 0, 0}] = 0.0;

        while (!pq.empty()) {
            auto [d, s, x, b] = pq.top(); pq.pop();
            if (x == en) return d;  // All locations visited
            if (dist[{s, x, b}] < d) continue;  // Skip if not optimal

            if (b) {
                // Returning phase
                for (int i = 0; i < n; ++i) {
                    if (x & (1 << i)) {
                        int nx = x & ~(1 << i);
                        double rt = time[i] * mul[s];
                        double nd = d + rt;
                        int ns = (s + (int)floor(rt)) % m;
                        auto key = make_tuple(ns, nx, 0);
                        if (!dist.count(key) || nd < dist[key]) {
                            dist[key] = nd;
                            pq.push({nd, ns, nx, 0});
                        }
                    }
                }
            } else {
                // Delivery phase
                for (int i = 1; i < (1 << n); ++i) {
                    if (__builtin_popcount(i) > k || (i & x)) continue;
                    int nx = x | i;
                    double dd = mx[i] * mul[s];
                    double nd = d + dd;
                    int ns = (s + (int)floor(dd)) % m;
                    auto key = make_tuple(ns, nx, 1);
                    if (!dist.count(key) || nd < dist[key]) {
                        dist[key] = nd;
                        pq.push({nd, ns, nx, 1});
                    }
                }
            }
        }

        return -1;  // Not possible
    }
};
