class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<long long> t(n);
        for (int i = 0; i < n; ++i) t[i] = (long long)costs[i] << 32 | capacity[i];
        sort(t.begin(), t.end());
        int a = 0, j = n - 1, m = 0;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            int c = t[i] >> 32, v = (int)t[i];
            p[i] = m = max(m, v);
            if (c < budget) a = max(a, v);
            while (j >= 0 && (t[j] >> 32) + c >= budget) j--;
            int k = min(j, i - 1);
            if (k >= 0) a = max(a, v + p[k]);
        }
        return a;
    }
};
