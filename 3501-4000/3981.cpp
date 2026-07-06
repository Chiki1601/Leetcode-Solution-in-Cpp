#define ll long long
const ll MOD = 1e9 + 7;
class Solution {
public:
    int interleaveCharacters(string a, string b, string target) {
        int n = a.size(), n2 = b.size(), m = target.size();
        static ll dp[101][101][2][2];
        static ll dpnxt[101][101][2][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;

        for (int i = 1; i <= m; i++) {
            memset(dpnxt, 0, sizeof(dpnxt));
            char x = target[i - 1];

            for (int prevb = 0; prevb <= n2; prevb++) {
                for (int t = 0; t < 2; t++) {
                    ll pref0[101], pref1[101];
                    pref0[0] = dp[0][prevb][0][t];
                    pref1[0] = dp[0][prevb][1][t];
                    for (int preva = 1; preva <= n; preva++) {
                        pref0[preva] = (pref0[preva - 1] + dp[preva][prevb][0][t]) % MOD;
                        pref1[preva] = (pref1[preva - 1] + dp[preva][prevb][1][t]) % MOD;
                    }
                    for (int preva = 1; preva <= n; preva++) {
                        if (a[preva - 1] != x) continue;
                        dpnxt[preva][prevb][1][t] =
                            (dpnxt[preva][prevb][1][t] + pref0[preva - 1] + pref1[preva - 1]) % MOD;
                    }
                }
            }

            for (int preva = 0; preva <= n; preva++) {
                for (int k = 0; k < 2; k++) {
                    ll pref0[101], pref1[101];
                    pref0[0] = dp[preva][0][k][0];
                    pref1[0] = dp[preva][0][k][1];
                    for (int prevb = 1; prevb <= n2; prevb++) {
                        pref0[prevb] = (pref0[prevb - 1] + dp[preva][prevb][k][0]) % MOD;
                        pref1[prevb] = (pref1[prevb - 1] + dp[preva][prevb][k][1]) % MOD;
                    }
                    for (int prevb = 1; prevb <= n2; prevb++) {
                        if (b[prevb - 1] != x) continue;
                        dpnxt[preva][prevb][k][1] =
                            (dpnxt[preva][prevb][k][1] + pref0[prevb - 1] + pref1[prevb - 1]) % MOD;
                    }
                }
            }

            memcpy(dp, dpnxt, sizeof(dp));
        }

        ll ans = 0;
        for (int preva = 0; preva <= n; preva++)
            for (int prevb = 0; prevb <= n2; prevb++)
                ans = (ans + dp[preva][prevb][1][1]) % MOD;
        return (int) ans;
    }
};
