using ll = long long;
const int mod = 1e9+7;

ll powm(ll x,ll n){
    ll ans=1;
    x%=mod;
    while(n){
        if(n&1) ans = (ans*x)%mod;
        x = (x*x)%mod;
        n>>=1;
    }
    return ans;
}

class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        ll ans=0;

        for(auto num:nums){
            ll w =num%10;
            ll d=num/10;

            string D = to_string(d);
            ll x = stoll(D.substr(0,w));
            ll y = stoll(D.substr(w));

            ans = (ans + powm(x,y))%mod;

        }
        return ans;
    }
};
