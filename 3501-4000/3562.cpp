class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> children(n);
        for (auto& h : hierarchy) {
            int u = h[0] - 1;
            int v = h[1] - 1;
            children[u].push_back(v);
        }

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2));

        function<vector<int>(int, int)> dfs = [&](int u, int s) -> vector<int> {
            if (!memo[u][s].empty()) {
                return memo[u][s];
            }

            vector<int> dp(budget + 1, 0);

            // Option 1: Do not buy the current node u
            vector<int> option1(budget + 1, 0);
            for (int v : children[u]) {
                vector<int> child_dp = dfs(v, 0);
                vector<int> temp(budget + 1, 0);
                for (int b = 0; b <= budget; ++b) {
                    for (int k = 0; k <= b; ++k) {
                        temp[b] = max(temp[b], option1[k] + child_dp[b - k]);
                    }
                }
                option1 = temp;
            }

            // Option 2: Buy the current node u
            int cost = s ? (present[u] / 2) : present[u];
            int profit_u = future[u] - cost;
            vector<int> option2(budget + 1, -1e9);

            if (cost >= 0) {
                vector<int> child_merged(budget + 1, 0);
                for (int v : children[u]) {
                    vector<int> child_dp = dfs(v, 1);
                    vector<int> temp(budget + 1, 0);
                    for (int b = 0; b <= budget; ++b) {
                        for (int k = 0; k <= b; ++k) {
                            temp[b] = max(temp[b], child_merged[k] + child_dp[b - k]);
                        }
                    }
                    child_merged = temp;
                }

                for (int b = 0; b <= budget; ++b) {
                    if (b >= cost) {
                        int remaining = b - cost;
                        if (remaining >= 0) {
                            option2[b] = profit_u + child_merged[remaining];
                        }
                    }
                }
            }

            for (int b = 0; b <= budget; ++b) {
                dp[b] = max(option1[b], max(option2[b], 0));
            }

            memo[u][s] = dp;
            return dp;
        };

        vector<int> root_dp = dfs(0, 0);
        int max_profit = 0;
        for (int b = 0; b <= budget; ++b) {
            max_profit = max(max_profit, root_dp[b]);
        }

        return max_profit;
    }
};
