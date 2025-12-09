const int N = 1e5;
int pa[N], deg[N], q[N];

class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& es, vector<int>& dp) {
        memset(pa, 0, sizeof(int) * n), memset(deg, 0, sizeof(int) * n);

        deg[0] = 2; // Prevent root from entering queue too early
        for (auto& e : es) {
            int a = e[0], b = e[1];
            deg[a]++, deg[b]++;
            pa[a] ^= b, pa[b] ^= a;
        }
        for (int i = 0; i < n; ++i) dp[i] = (dp[i] << 1) - 1; // Map 0 -> -1, 1 -> 1

        int qi = 0;
        for (int s = 0; s < n; ++s) {
            // Use XOR property to dynamically remove child and point to grand-parent in the loop update
            for (int i = s, p; deg[i] == 1; pa[p] ^= i, --deg[p], i = p) {
                q[qi++] = i;
                deg[i] = 0;
                p = pa[i];
                if (dp[i] > 0) dp[p] += dp[i];
            }
        }
        
        while (qi--) {
            int i = q[qi];
            // Add parent contribution (excluding self impact)
            dp[i] += max(0, dp[pa[i]] - max(0, dp[i]));
        }
        return dp;
    }
};
