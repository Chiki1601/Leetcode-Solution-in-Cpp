class Solution {
private:
    long pow(long x, long n, long mod) {
        long result = 1, p = x % mod;
        while (n) {
            if (n & 1) {
                result = (result * p) % mod;
            }
            p = (p * p) % mod;
            n >>= 1;
        }
        return result;
    }
    
public:
    int stringCount(int n) {
        long count = 0, mod = 1e9 + 7;
        return ((
            + pow(26, n, mod)
            - (n + 75) * pow(25, n - 1, mod)
            + (2 * n + 72) * pow(24, n - 1, mod)
            - (n + 23) * pow(23, n - 1, mod)
        ) % mod + mod) % mod;
    }
};
