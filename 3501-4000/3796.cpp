class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions,
                   vector<int>& diff) {
        vector<int> restriction(n, 1e9);

        for (auto& r : restrictions) {
            restriction[r[0]] = r[1];
        }

        for (int i = n - 2; i >= 0; i--) {
            restriction[i] = min(restriction[i], restriction[i + 1] + diff[i]);
        }

        restriction[0] = 0;

        int ans = 0;
        for (int i = 1; i < n; i++) {
            restriction[i] = min(restriction[i], restriction[i - 1] + diff[i - 1]);
            ans = max(ans, restriction[i]);
        }

        return ans;
    }
}
