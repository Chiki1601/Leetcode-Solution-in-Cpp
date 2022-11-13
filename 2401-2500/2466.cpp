class Solution 
{
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int> dp(high+1,0);
        dp[0] = 1;
        int mod = 1000000007;
        
        for (int k = 1; k <= high; ++k)
        {
            if (k >= zero) dp[k] += dp[k-zero] % mod;
            if (k >= one)  dp[k] += dp[k-one]  % mod;
        }
        
        long long cnt = 0;
        for (int k = low; k <= high; ++k) cnt = (cnt + dp[k]) % mod;
        return cnt;
    }
};
