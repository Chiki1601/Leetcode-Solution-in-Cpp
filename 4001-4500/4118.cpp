class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return -1;
        }
        int m = *max_element(nums.begin(), nums.end()) + n, INF = 1e8;

        auto build = [&](const vector<int>& b) {
            vector<vector<int>> f(n, vector<int>(m + 1, INF));
            for (int i = 0; i < n; i++) {
                for (int v = 1; v <= m; v++) {
                    f[i][v] = min(f[i][v - 1], (i ? f[i - 1][v - 1] : 0) + abs(b[i] - v));
                }
            }
            return f;
        };

        auto l = build(nums);
        auto r = build(vector<int>(nums.rbegin(), nums.rend()));

        int ans = INF;
        for (int i = 1; i < n - 1; i++) {
            for (int v = 1; v <= m; v++) {
                ans = min(ans, l[i - 1][v - 1] + r[n - 2 - i][v - 1] + abs(nums[i] - v));
            }
        }
        return ans;
    }
};   
   
