typedef long long   ll;
ll mod = 1000000007;

class Solution {
public:
    ll dp[101][2][2][11];

    ll helper(ll pos, ll tight, ll isZero, ll prevDigit, string &s) {
        if (pos == (ll) s.size()) {
            if (isZero) return 0;
            return 1;
        }

        if (dp[pos][tight][isZero][prevDigit + 1] != -1) return dp[pos][tight][isZero][prevDigit + 1];

        ll res = 0;
        ll limit;

        if (tight) limit = (s[pos] - '0');
        else limit = 9;

        for (ll curDigit = 0; curDigit <= limit; curDigit++) {

            ll newTight = tight;
            if (tight && curDigit < limit) newTight = 0;

            ll willBeZero = isZero;
            if (isZero && curDigit > 0) willBeZero = 0;

            if (isZero) {
                res += helper(pos + 1, newTight, willBeZero, curDigit, s);
                res %= mod;
            } else {
                if (abs(curDigit - prevDigit) == 1) {
                    res += helper(pos + 1, newTight, willBeZero, curDigit, s);
                    res %= mod;
                }
            }
        }

        dp[pos][tight][isZero][prevDigit + 1] = res;
        return res;
    }
    
    int countSteppingNumbers(string low, string high) {
        
        memset(dp, -1, sizeof(dp));
        ll l = helper(0, 1, 1, -1, low);
        
        memset(dp, -1, sizeof(dp));
        ll r = helper(0, 1, 1, -1, high);
        
        ll res = r - l;
        res %= mod;
        res += mod;
        res %= mod;
        
        ll add = true;
        for (ll i = 1; i < (ll) low.size(); i++)
            if (abs(low[i] - low[i - 1]) != 1) add = false;
        if (add) res++;
        
        res %= mod;
        return res;
    }
};
