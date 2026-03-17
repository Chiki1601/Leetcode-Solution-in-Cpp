using ll = long long;

class Solution {
public:
    long long countFancy(long long l, long long r) {
        
        // Stage 1: Precompute which sums are "good"
        vector<ll> v(145, 0);
        for(ll i=0; i<145; i++) {
            if(i<10) v[i]=1;
            else {
                string str = to_string(i);
                ll inc=1, dec=1;
                for(ll j=0; j<str.size()-1; j++) {
                    if(str[j]>=str[j+1]) inc=0;
                    if(str[j]<=str[j+1]) dec=0;
                }
                if(inc||dec) v[i]=1;
            }
        }
        
        // Stage 2: BFS — Enumerate all of Set A
        vector<ll> g, q;
        for(ll i=0; i<=9; i++) {
            g.push_back(i);
            q.push_back(i);
        }
        
        ll hd = 0;
        while(hd<q.size()) {
            ll curr = q[hd++];
            ll ld = curr%10;
            for(ll d=ld+1; d<=9; d++) {
                ll nxt = curr*10+d;
                q.push_back(nxt);
                g.push_back(nxt);
            }
        }
        
        q.clear();
        for(ll i=0; i<=9; i++) q.push_back(i);
        
        hd = 0;
        while(hd<q.size()) {
            ll curr = q[hd++];
            ll ld = curr%10;
            for(ll d=0; d<ld; d++) {
                ll nxt = curr*10+d;
                q.push_back(nxt);
                g.push_back(nxt);
            }
        }
        
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        
        // Stage 3: Digit DP — Count |B ∩ [L, R]| = f(R) - f(L-1)
        ll ans = 0;
        ll bnd[2] = {r, l-1};
        ll res[2] = {0, 0};
        
        for(ll k=0; k<2; k++) {
            ll n = bnd[k];
            if(n<0) continue;
            
            string s = to_string(n);
            ll len = s.size();
            ll maxi = len*9;
            
            vector<vector<vector<ll>>> dp(len+1, vector<vector<ll>>(maxi+1, vector<ll>(2, 0)));
            dp[0][0][1] = 1;
            
            for(ll i=0; i<len; i++) {
                for(ll j=0; j<=maxi; j++) {
                    for(ll m=0; m<=1; m++) {
                        if(dp[i][j][m]==0) continue;
                        
                        ll lim;
                        if(m==1) lim = s[i]-'0';
                        else lim = 9;
                        
                        for(ll d=0; d<=lim; d++) {
                            ll nt;
                            if((m==1 && d==lim)) {
                                nt=1;
                            }
                            else nt=0;
                            dp[i+1][j+d][nt] += dp[i][j][m];
                        }
                    }
                }
            }
            
            ll total = 0;
            for(ll b=0; b<=maxi; b++) {
                if(v[b]) {
                    total += dp[len][b][0] + dp[len][b][1];
                }
            }
            res[k] = total;
        }
        
        ans = res[0] - res[1];
        
        // Stage 4: Add |A \ B| — Set A members with a bad digit sum
        for(ll i=0; i<(ll)g.size(); i++) {
            ll x = g[i];
            if(x>=l && x<=r) {
                ll tmp = x;
                ll sum = 0;
                while(tmp>0) {
                    sum += tmp%10;
                    tmp /= 10;
                }
                if(!v[sum]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
