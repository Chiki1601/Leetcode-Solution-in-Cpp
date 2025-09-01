class Solution {
public:
  long long maxProduct(vector<int>& nums) {
    int max_n = *max_element(begin(nums), end(nums));
    int msb = log2(max_n), max_mask = (1 << (msb + 1)) - 1;
    vector<int> dp(max_mask + 1);
    for (int x : nums) 
        dp[x] = x;
    for (int b = 0; b <= msb; ++b)
        for (int mask = 0; mask < max_mask; ++mask)
            if (mask & (1 << b))
                dp[mask] = max(dp[mask], dp[mask ^ (1 << b)]);
    long long ans = 0;
    for (int n : nums)
        ans = max(ans, 1LL * n * dp[max_mask ^ n]);
    return ans;       
}
   
};
