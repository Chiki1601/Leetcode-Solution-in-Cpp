#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> score_add = {0, 1, 2};
        vector<int> cost_add  = {0, 1, 1};

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int cost_used = 0; cost_used <= k; cost_used++) {
                    if (dp[i][j][cost_used] == -1) continue;

                    int cur_score = dp[i][j][cost_used];

                    // Move DOWN
                    if (i + 1 < m) {
                        int new_cost = cost_used + cost_add[grid[i + 1][j]];
                        if (new_cost <= k) {
                            int new_score = cur_score + score_add[grid[i + 1][j]];
                            dp[i + 1][j][new_cost] = max(dp[i + 1][j][new_cost], new_score);
                        }
                    }

                    // Move RIGHT
                    if (j + 1 < n) {
                        int new_cost = cost_used + cost_add[grid[i][j + 1]];
                        if (new_cost <= k) {
                            int new_score = cur_score + score_add[grid[i][j + 1]];
                            dp[i][j + 1][new_cost] = max(dp[i][j + 1][new_cost], new_score);
                        }
                    }
                }
            }
        }

        int best = -1;
        for (int c = 0; c <= k; c++) {
            best = max(best, dp[m - 1][n - 1][c]);
        }
        return best;
    }
};
