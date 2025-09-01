#define ll long long
#define MOD 1000000007

class fentree{
    vector<ll> f;
    int n;
public:
    fentree() {}
    fentree(int size) {
        this->n = size + 1;
        f.resize(size + 1, 0);
    }
    void update(int x, ll val) {
        ++x;
        while (x < n) {
            (f[x] += val)%=MOD;    x += (x & (-x));
        }
    }
    ll query(int x) {
        ++x;
        ll ans = 0;
        while (x > 0) {
            (ans += f[x])%=MOD;    x -= (x & (-x));
        }
        return ans;
    }
    ll query(int l, int r) {
        return (query(r) - query(l - 1) + MOD)%MOD;
    }
};

class Solution {
    ll cntIncreasingSubseq(vector<ll> &v, vector<ll> &mp){
        if(v.empty()) return 0;
        int n = v.size(), indx = 0;
        vector<ll> temp = v;
        sort(temp.begin(),temp.end());
        for(auto x : temp) mp[x] = indx++;
        fentree ft(n);
        for(int i = 0; i<n; ++i){
            ll add = ft.query(0,mp[v[i]]-1);
            ft.update(mp[v[i]],add+1);
        }
        return ft.query(0,n-1);
    }
public:
    int totalBeauty(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(),nums.end());
        vector<ll> cnt(mx+1,0);
        vector<vector<ll>> divisors(mx+1);
        for(int i = 1; i<=mx; ++i){
            for(int j = i; j<=mx; j+=i){
                divisors[j].push_back(i);
            }
        }
        vector<vector<ll>> multiples_in_nums(mx+1);
        for(auto x : nums){
            for(auto d : divisors[x]){
                multiples_in_nums[d].push_back(x);
            }
        }
        ll ans = 0;
        vector<ll> mapping(mx+1);
        for(int g = mx; g>=1; --g){
            vector<ll> &v = multiples_in_nums[g];
            cnt[g] = cntIncreasingSubseq(v,mapping);
            for(int gg = 2*g; gg<=mx; gg+=g){
                cnt[g] -= cnt[gg];
                if(cnt[g]<0) cnt[g] += MOD;
            }
            (ans += (g*cnt[g])%MOD)%=MOD;
        }
        return ans;
    }
};
