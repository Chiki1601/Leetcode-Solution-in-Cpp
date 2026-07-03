class Solution {
public:
      long long maxSubarraySum(vector<int>& A, int k) {
        long long res = -1e9, dp0 = 0, dpb = 0, dpc = 0, dp1 = 0;
        for (long long a: A) {
            long long b = a * k, c = a / k;
            dp1 = max({dp1 + a, dpb + a, dpc + a});
            dpb = max({dp0 + b, dpb + b, b});
            dpc = max({dp0 + c, dpc + c, c});
            dp0 = max(dp0 + a, a);
            res = max({res, dp0, dpb, dpc, dp1});
        }
        return res;
    }
};
