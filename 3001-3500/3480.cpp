typedef long long ll;
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        // Swap to get correct left / right endpoint
        for(int i = 0; i < m; i++) {
            if (conflictingPairs[i][0] > conflictingPairs[i][1])
                swap(conflictingPairs[i][0], conflictingPairs[i][1]);
        }
        // Sort with right endpoint, then left endpoint
        sort(conflictingPairs.begin(), conflictingPairs.end(), [](auto& x, auto& y) {
            return x[1] != y[1] ? x[1] < y[1] : x[0] < y[0];
        });
        int j = 0;
        // Subarrays with left end in [mxlb, curlb] (both inclusive) can contribute to pair `cur`
        int mxlb = 1, curlb = 1, cur = -1;
        vector<ll> res(m, 0);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            // At each step, we need to process all pairs that has appeared
            // Sorting with left endpoint also guarantees correctness during the processing
            while(j < m && conflictingPairs[j][1] <= i) {
                if (cur == -1) {
                    // No contribution now
                    // However, if left end is to the left of mxlb
                    // it will cover another pair, so can't contribute to it
                    if (mxlb <= conflictingPairs[j][0]) {
                        curlb = conflictingPairs[j][0];
                        cur = j;
                    }
                } else if (conflictingPairs[j][0] < curlb) {
                    // No challenge to current pair
                    mxlb = max(mxlb, conflictingPairs[j][0] + 1);
                } else if (conflictingPairs[j][0] == curlb) {
                    // Same left endpoint, can't contribute
                    mxlb = curlb + 1;
                    cur = -1;
                } else {
                    // Refresh contribution to pair j
                    mxlb = curlb + 1;
                    curlb = conflictingPairs[j][0];
                    cur = j;
                }
                j++;
            }
            if (cur != -1) {
                // Do the contribution!
                res[cur] += curlb - mxlb + 1;
            }
            // Calculate base problem result, squeezed into the same iteration
            if (cur == -1) ans += i - mxlb + 1;
            else ans += i - curlb;
        }
        ll resmx = 0;
        for(int i = 0; i < m; i++) {
            resmx = max(resmx, res[i]);
        }
        return ans + resmx;
    }
};
