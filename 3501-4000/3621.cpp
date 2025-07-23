#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
const ll mod = 1e9 + 7, MX = 2e5 + 5;
const ll INF = 1e18;
constexpr ll pct(int x) { return __builtin_popcount(x); }
constexpr ll bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

class Solution {
public:
    string s;
    ll cnt[66], dp[64][64][2];

    ll rec(int idx, int lim, int tight) {
       if (lim < 0) return 0;
       if (idx >= s.length() && lim == 0) return 1LL;
       if (idx >= s.length()) return 0;
       if (dp[idx][lim][tight] != -1) return dp[idx][lim][tight];
       int limit = tight ? s[idx] - '0' : 1;
       ll num_cnt = 0;
       for (int i = 0; i <= limit; ++i)
           num_cnt += rec(idx + 1, lim - i, tight && (i == limit));
       return dp[idx][lim][tight] = num_cnt;
    }

    long long popcountDepth(long long n, int k) {
        if(k==0)return 1;
        memset(cnt, 0, sizeof(cnt));
        cnt[1] = 0;
        for (int i = 2; i <= 64; ++i)
            cnt[i] = cnt[pct(i)] + 1;
        int flag = 0;
        for (ll i = 62; i >= 0; --i) {
            if ((n >> i) & 1LL) flag = 1;
            if (flag) s.pb(((n >> i) & 1LL) + '0');
        }
        ll ans = 0;
        for (int i = 1; i <= 62; ++i) {
            if (cnt[i] == k - 1) {
                memset(dp, -1, sizeof(dp));
                ans += rec(0, i, 1);
                if(i==1)--ans;
            }
        }
        return ans;
    }
};
