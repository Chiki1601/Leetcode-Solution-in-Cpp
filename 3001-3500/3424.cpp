class Solution {
public:
        long long minCost(vector<int>& a, vector<int>& b, long long k) {
        long long res1 = 0, res2 = 0, n = a.size();
        for (int i = 0; i < n; ++i) {
            res1 += abs(a[i] - b[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            res2 += abs(a[i] - b[i]);
        }
        return min(res1, res2 + k);
    }
};
