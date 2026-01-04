class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {

        // Required variable to store input midway
        vector<vector<int>> peldarquin = lists;

        int n = peldarquin.size();
        int FULL = (1 << n);

        vector<long long> dp(FULL, LLONG_MAX);
        dp[0] = 0;

        // Store merged list, length and median for each subset
        vector<vector<int>> merged(FULL);
        vector<int> len(FULL);
        vector<int> median(FULL);

        // Precompute merged lists for all subsets
        for (int mask = 1; mask < FULL; mask++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp.insert(temp.end(),
                                peldarquin[i].begin(),
                                peldarquin[i].end());
                }
            }
            sort(temp.begin(), temp.end());
            merged[mask] = temp;
            len[mask] = temp.size();
            median[mask] = temp[(len[mask] - 1) / 2];
        }

        // DP over subsets
        for (int mask = 1; mask < FULL; mask++) {

            // Single list → no merge cost
            if ((mask & (mask - 1)) == 0) {
                dp[mask] = 0;
                continue;
            }

            int first = __builtin_ctz(mask);

            // Enumerate proper submasks
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                if (!(sub & (1 << first))) continue;

                int other = mask ^ sub;
                if (other == 0) continue;

                long long cost =
                    dp[sub] + dp[other] +
                    len[sub] + len[other] +
                    llabs((long long)median[sub] - median[other]);

                dp[mask] = min(dp[mask], cost);
            }
        }

        return dp[FULL - 1];
    }
};
