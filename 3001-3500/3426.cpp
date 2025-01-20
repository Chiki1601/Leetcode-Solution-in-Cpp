#include <bits/stdc++.h>
using namespace std;
long long mod_exp(long long base, int exp, long long mod) {
    long long ans = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return ans;
}
const long long FMOD = 1e9 + 7;
vector<long long> factorial {1,1}, invfactorial {1,1};

long long calcFactorial(long long n) {
    for(long long i = factorial.size(); i <= n; i++) {
        factorial.push_back(i * factorial[i - 1]);
    }
    return factorial[n];
}
long long modfactorial(long long n) {
    for(long long i = factorial.size(); i <= n; i++) {
        factorial.push_back((i * factorial[i - 1]) % FMOD);
        invfactorial.push_back((mod_exp(i, FMOD-2, FMOD) * invfactorial[i - 1]) % FMOD);
    }
    return factorial[n];
}
const long long MAXFACTORIALN = 100'001;
auto precomputeModFactorial = []() { modfactorial(MAXFACTORIALN); return true; }();
long long nCkMod(int N, int K) {
    return factorial[N] * invfactorial[K] % FMOD * invfactorial[N-K] % FMOD;
}
const long long MOD = 1e9 + 7;
const long long DIVIDE_BY_6 = mod_exp(6, MOD-2, MOD);
class Solution {
public:
    int distanceSum(int n, int m, int k) {
        return nCkMod(n*m-2, k-2) * (
            (1LL * m * m % MOD * (n - 1) % MOD * (n) % MOD * (n + 1) % MOD * DIVIDE_BY_6 % MOD) + 
            (1LL * n * n % MOD * (m - 1) % MOD * (m) % MOD * (m + 1) % MOD * DIVIDE_BY_6 % MOD)) % MOD;
    }
};
