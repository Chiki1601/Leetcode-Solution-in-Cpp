class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind initial_uf(n);
        // Observation 1: Find minimum s_i for must-have edges.
        int min_s = INT_MAX;
        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (!must) continue;
            min_s = min(min_s, s);
            // Observation 2: The must-have edges form a cycle.
            if (!initial_uf.unionSet(u, v)) return -1;
        }

        // store snapshots
        vector<int> baseRank = initial_uf.rank;
        vector<int> baseRoot = initial_uf.root;

        auto check = [&](int min_stability) -> bool {
            // Observation 1
            if (min_stability > min_s) return false;

            // This copies the initial state, where all `must-have edges` are connected.
            UnionFind uf(n);
            uf.rank = baseRank;
            uf.root = baseRoot;

            // Observation 3: List of edges to consider an upgrade
            vector<pair<int,int>> upgrade;
            for (auto& e : edges) {
                int u = e[0], v = e[1], s = e[2], must = e[3];
                if (must) continue;
                // Observation 3
                if (s >= min_stability) {
                    uf.unionSet(u, v);
                } else if (s * 2 >= min_stability) {
                    upgrade.emplace_back(u, v);
                }
            }

            int r = k;  // number of upgrades remaining
            for (auto& p : upgrade) {
                int u = p.first, v = p.second;
                if (uf.isConnected(u, v)) continue;
                if (!r) return false;
                uf.unionSet(u, v);
                --r;
            }

            // Observation 3
            int root0 = uf.find(0);
            for (int i = 1; i < n; ++i)
                if (uf.find(i) != root0) return false;
            return true;
        };

        int right = 0;
        for (auto& e : edges) right = max(right, e[2]);
        right *= 2;
        int left = -1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (check(mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
