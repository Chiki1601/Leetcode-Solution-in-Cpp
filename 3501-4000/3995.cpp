class Solution {
public:
    long long minCost(string source, string target,
                      vector<vector<string>>& rules,
                      vector<int>& costs) {

        int n = source.size();
        if (n != target.size()) return -1;

        const long long INF = 4e18;
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        struct Rule {
            string pat, rep;
            int len;
            long long cost;
        };

        vector<Rule> all;

        for (int i = 0; i < rules.size(); i++) {
            int stars = 0;
            for (char c : rules[i][0])
                if (c == '*') stars++;

            all.push_back({rules[i][0], rules[i][1],
                           (int)rules[i][0].size(),
                           (long long)costs[i] + stars});
        }

        for (int i = n - 1; i >= 0; i--) {

            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (auto &r : all) {

                if (i + r.len > n) continue;

                bool ok = true;

                for (int k = 0; k < r.len; k++) {
                    if (r.pat[k] != '*' && r.pat[k] != source[i + k]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) continue;

                for (int k = 0; k < r.len; k++) {
                    if (r.rep[k] != target[i + k]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) continue;

                dp[i] = min(dp[i], r.cost + dp[i + r.len]);
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};
