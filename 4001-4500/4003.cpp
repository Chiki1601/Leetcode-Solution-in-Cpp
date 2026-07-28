class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        static constexpr int DIRS[5][2] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // (0,0) = wait
        auto idx = [n](int i, int j, int p) { return 2 * (i * n + j) + (p > 0); };

        priority_queue<tuple<long long, int, int, int>,
                       vector<tuple<long long, int, int, int>>, greater<>> pq;
        vector<uint8_t> seen(2 * m * n);
        pq.push({1, 0, 0, 1});  // (fee, i, j, p), start with fee = 1
        while (!pq.empty()) {
            auto [d, i, j, p] = pq.top(); pq.pop();
            if (seen[idx(i, j, p)]) continue;
            seen[idx(i, j, p)] = 1;
            if (i == m - 1 && j == n - 1) return d;
            for (auto [di, dj] : DIRS) {
                int ii = i + di, jj = j + dj;
                if (0 <= ii && ii < m && 0 <= jj && jj < n && !seen[idx(ii, jj, -p)]) {
                    long long fee = (di || dj) ? (ii + 1) * (jj + 1) : 0;
                    pq.push({d + fee + (di + dj != p) * penalty[i][j], ii, jj, -p});
                }
            }
        }
        return -1;
    }
};
