using ll = long long;
class Solution {
public:
    int countEffective(vector<int>& a) {
        const int n = a.size();
        const int MOD = 1e9 + 7;
        int OR = 0;
        for(auto& x : a) {
            OR |= x;
        }
        const int B = 63 - __builtin_clzll(OR) + 1;
        vector<int> dp(1 << B);
        for(auto& x : a) {
            dp[x]++;
        }
        for(int j = 1; j < 1 << B; j <<= 1) {
            for(int i = 0; i < 1 << B; i++) {
                if(i & j) {
                    dp[i] += dp[i ^ j];
                }
            }
        }
        vector<int> p2(n + 1);
        p2[0] = 1;
        for(int i = 1; i <= n; i++) {
            p2[i] = (p2[i - 1] * 2) % MOD;
        }
        for(int i = 0; i < 1 << B; i++) {
            dp[i] = p2[dp[i]] - 1;
        }
        for(int j = 1; j < 1 << B; j <<= 1) {
            for(int i = 0; i < 1 << B; i++) {
                if(i & j) {
                    dp[i] = (dp[i] - dp[i ^ j] + MOD) % MOD;
                }
            }
        }
        int res = 1;
        for(int i = 0; i < OR; i++) {
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
