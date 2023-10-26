class Solution {
#define ll long long
private:
    ll mod = 12345;

    ll gcdEx(ll a, ll b, ll* x, ll* y) {
        // Base Case
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }
        ll x1, y1;
        ll gcd = gcdEx(b % a, a, &x1, &y1);
        *x = y1 - (b / a) * x1;
        *y = x1;
        return gcd;
    }
    
    ll modInv(ll A) {
        ll x, y;
        ll g = gcdEx(A, mod, &x, &y);
        ll res = (x % mod + mod) % mod;
        return res;
    }
    
    ll int power(ll x, ll y) {
        // Code here
        ll res = 1;
        while(y > 0){
            if(y % 2 == 1){
                res = (res * x) % mod;
            }
            y >>= 1;
            x=(x % mod * x % mod) % mod;
        }
        return (res % mod + mod) % mod;
    }
    
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        ll prd = 1;
        ll c3 = 0, c5 = 0, c823 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x = grid[i][j];
                while(x % 3 == 0) {
                    x /= 3;
                    c3++;
                }
                while(x % 5 == 0) {
                    x /= 5;
                    c5++;
                }
                while(x % 823 == 0) {
                    x /= 823;
                    c823++;
                }
                prd *= x;
                prd %= mod;
            }
        }
        vector<vector<int>> ret(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ll x = grid[i][j];
                ll cn3 = 0, cn5 = 0, cn823 = 0;
                while(x % 3 == 0) {
                    x /= 3;
                    cn3++;
                }
                while(x % 5 == 0) {
                    x /= 5;
                    cn5++;
                }
                while(x % 823 == 0) {
                    x /= 823;
                    cn823++;
                }
                ll inv = modInv(x);
                long long temp = inv * 1ll * prd;
                cn3 = c3 - cn3;
                cn5 = c5 - cn5;
                cn823 = c823 - cn823;
                temp *= power(3, cn3);
                temp %= mod;
                temp *= power(5, cn5);
                temp %= mod;
                temp *= power(823, cn823);
                temp %= mod;
                ret[i][j] = temp;
            }
        }
        return ret;
    }
};
