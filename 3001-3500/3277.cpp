class Solution {
public:
       vector<int> maximumSubarrayXor(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size(), m = queries.size();
        unordered_map<int, vector<int>> d;
        for (int qi = 0; qi < m; ++qi) {
            d[queries[qi][1] - queries[qi][0]].push_back(qi);
        }
        vector<int> cur = A, res(m);
        for (int v = 0; v < n; ++v) {
            for (int qi : d[v]) {
                res[qi] = cur[queries[qi][0]];
            }
            for (int i = 0; i < n - v - 1; ++i) {
                A[i] ^= A[i + 1];
                cur[i] = max({cur[i], cur[i + 1], A[i]});
            }
        }
        return res;
    }
};
