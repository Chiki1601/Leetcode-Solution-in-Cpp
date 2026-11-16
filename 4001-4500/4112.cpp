class Solution {
public:
    long long maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        
        vector<int> order;
        order.push_back(0);
        for (int i = 0; i < order.size(); ++i) {
            int u = order[i];
            for (int v : children[u]) {
                order.push_back(v);
            }
        }
        
        vector<long long> dp(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            int u = order[i];
            if (children[u].empty()) {
                dp[u] = score[u];
                continue;
            }
            long long totalSum = 0;
            long long minChild = 1e18;
            for (int v : children[u]) {
                totalSum += dp[v];
                if (dp[v] < minChild) {
                    minChild = dp[v];
                }
            }
            if (op[u] == 1) {
                dp[u] = score[u] + totalSum - minChild;
            } else {
                dp[u] = score[u] + totalSum - min(0LL, minChild);
            }
        }
        return dp[0];
    }
};
