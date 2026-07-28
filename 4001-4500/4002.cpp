class Solution {
    const int mod = 1e9 + 7;
    
    long long power(long long a, long long b) {
        long long ans = 1;
        while(b > 0) {
            if(b & 1) ans = (a * ans) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    long long nCr(int n , int r, vector<long long>& fact, vector<long long>& invfact) {
        if(r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
    }
    
public:
    int countValidSequences(int n, int k) {
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        vector<long long> invfact(n + 1);
        invfact[n] = power(fact[n], mod - 2);
        for(int i = n ; i >= 1; i--) {
            invfact[i - 1] = (invfact[i] * i) % mod;
        }
        long long total = nCr(n - 1, k - 1, fact, invfact);
        long long odd = 0;
        if((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = nCr(m + k - 1, k - 1, fact, invfact);
        }
        return (total - odd + mod) % mod;
    }
};
