using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 1001;

class Solution {
private:
    ll dp[MAXN][MAXN];
    ll inv[MAXN];
    ll fac[MAXN];
    ll ifac[MAXN];
    ll ipow[MAXN];

    void precompute(ll n, ll x, ll y) {
        inv[1] = 1;
        for (ll i = 2; i <= max(n, x); ++i) {
            inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        }

        fac[0] = ifac[0] = 1;
        for (ll i = 1; i <= max(n, x); ++i) {
            fac[i] = fac[i - 1] * i % MOD;
            ifac[i] = ifac[i - 1] * inv[i] % MOD;
        }

        ipow[0] = 1;
        for (ll i = 1; i <= x; ++i) {
            ipow[i] = ipow[i - 1] * y % MOD;
        }

        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= x; ++j) {
                dp[i][j] = -1;
            }
        }
    }

    ll C(ll n, ll k) {
        if (k > n) return 0;
        return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
    }

    ll StirlingSecondKind(ll N, ll M) {
        if (M == 0 || M > N) return 0;
        if (M == 1 || M == N) return 1;
        if (dp[N][M] != -1) return dp[N][M];

        return dp[N][M] = (M * StirlingSecondKind(N - 1, M) % MOD + StirlingSecondKind(N - 1, M - 1)) % MOD;
    }

public:
    ll numberOfWays(ll n, ll x, ll y) {
        precompute(n, x, y);
        int res = 0;

        for (ll i = 1; i <= x; ++i) {
            res = (res + C(x, i) * StirlingSecondKind(n, i) % MOD * fac[i] % MOD * ipow[i] % MOD) % MOD;
        }

        return res;
    }
};
