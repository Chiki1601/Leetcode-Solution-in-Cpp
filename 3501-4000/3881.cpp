class Solution {
private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int countVisiblePeople(int n, int pos, int k) {
        long long MOD = 1000000007;
        
        if (k > n - 1) {
            return 0;
        }

        long long m = n - 1;
        long long r = std::min((long long)k, m - k);
        
        long long numerator = 1;
        long long denominator = 1;
        
        // Calculate numerator and denominator for C(m, r)
        for (long long i = 0; i < r; ++i) {
            numerator = (numerator * (m - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }
        
        // Calculate C(m, r) 
        long long modInverse = power(denominator, MOD - 2, MOD);
        long long combinations = (numerator * modInverse) % MOD;
        
        // The person at `pos` has 2 choices ('L' or 'R'), so multiply by 2
        return (2 * combinations) % MOD;
    }
};
