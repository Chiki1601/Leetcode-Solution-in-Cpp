class Solution {
public:
     int minRemovals(vector<int>& A, int target) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int a : A) {
            target ^= a;
            vector<pair<int, int>> items(dp.begin(), dp.end());
            for (auto& item : items) {
                int v = item.first, c = item.second;
                int next_v = v ^ a;
                int current_c = dp.count(next_v) ? dp[next_v] : 50;
                if (c + 1 < current_c) {
                    dp[next_v] = c + 1;
                }
            }
        }
        return dp.count(target) ? dp[target] : -1;
    }
};
