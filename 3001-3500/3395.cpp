#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define SORT(arr) sort(arr.begin(),arr.end())
#define mod (int)(1e9+7)
#define ll long long
#define v(a) vector<a>
#define p(a,b) pair<a,b>
#define vv(a) vector<vector<a>>
#define ump(a,b) unordered_map<a,b>
#define omp(a,b) map<a,b>
#define ust(a) unordered_set<a>
#define ost(a) set<a>
#define sum(arr) accumulate(arr.begin(),arr.end(),0)
#define pb push_back
#define pob pop_back
#define maxheap(a) priority_queue<a>
#define minheap(a) priority_queue<a, vector<a>, greater<a>>
#define REVERSE(arr) reverse(arr.begin(),arr.end())
#define all(cont) cont.begin(), cont.end()
#define iM INT_MAX
#define im INT_MIN
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pbds(a) tree<a, null_type, less<a>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// https://codeforces.com/blog/entry/11080
int binExp(int a, int b){
    long long res = 1;
    while(b > 0){
        if(b & 1) res = (res * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return res;
}
int power(long long x, long long y, int p = 1e9+7){
    int res = 1;
    x = x % p; // Update x if it is more than or equal to p
    if (x == 0) return 0; // In case x is divisible by p
    while (y > 0){
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int MMI(int a){
    return binExp(a, mod - 2);
}
v(int) fact;
void getFact(int n) {
    fact.resize(n + 1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = (i * 1ll * fact[i - 1]) % mod;
    }
    return;
}
unsigned long long cnr(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    unsigned long long numerator = fact[n];
    unsigned long long denominator1 = fact[n - k];
    unsigned long long denominator2 = fact[k];
    unsigned long long denominatorInverse1 = MMI(denominator1);
    unsigned long long denominatorInverse2 = MMI(denominator2);
    return (((numerator * denominatorInverse1) % mod) * denominatorInverse2) % mod;
}

class Solution {
public:
    int subsequencesWithMiddleMode(vector<int>& nums) {
        int n = nums.size();
        ump(int, int) f, tt;
        ump(int, int) ff, ft;
        for(int e: nums) f[e]++, tt[e]++, ft[e]++;
        long long ans = 0;
        // fact.assign(100000, 1);
        getFact(1001); // Precomputation of factorials in linear time

        v(int) suf(n+1), pre(n+1); // will tell total combinations of cnr(x, 2) will exist before/after index i for distinct elements there

        for(int i=0;i<n;i++){
            int sum = 0;
            for(auto e: tt){
                if(e.second < 2) continue;
                sum+= cnr(e.second, 2);
                sum%= mod;
            }
            tt[nums[i]]--;

            suf[i] = sum;
        }

        for(int e: nums) tt[e]++;

        for(int i=n-1;i>=0;i--){
            int sum = 0;
            for(auto e: tt){
                if(e.second < 2) continue;
                sum+= cnr(e.second, 2);
                sum%= mod;
            }
            tt[nums[i]]--;

            pre[i] = sum;
        }

        v(int) cnr2(n+1);
        for(int i=0;i<=n;i++) cnr2[i] = cnr(i, 2); // Precomputation of cnr(i, 2) in linear time
        ft[nums[0]]--;
        ft[nums[1]]--;
        ff[nums[0]]++;
        ff[nums[1]]++;
        for(int i=2;i<n;i++){
            ft[nums[i]]--;
            // cout<< i << ft[nums[i]] << ff[nums[i]] << endl;
            if(f[nums[i]] < 2){
                ff[nums[i]]++;
                continue;
            }
            
            // cout<< i << nums[i] << ff[nums[i]] << ft[nums[i]] << endl;
            int lt = (pre[i-1] - cnr2[ff[nums[i]]] + mod)%mod;
            int rt = (suf[i+1] - cnr2[ft[nums[i]]] + mod)%mod;
            
            ans+= (cnr2[i] * 1ll * cnr2[n-i-1])%mod;
            ans%= mod;
            int left = i - ff[nums[i]];
            int right = n - (i+1) - (f[nums[i]]-ff[nums[i]]-1);
            ans = (ans + mod - (cnr2[left] * 1ll * cnr2[right])%mod)%mod;
            
            
            if(ff[nums[i]] > 0){
               for(auto &e: ff){
                    if(e.first == nums[i]) continue;
                    right = n - (i+1) - ft[nums[i]] - ft[e.first];
                    left = i - ff[nums[i]];
                    
                    int one_time = (ff[nums[i]] * 1ll * (e.second * 1ll * (right * 1ll * ft[e.first])%mod)%mod)%mod;
                    // cout<< e.first << i << " " << ans << one_time << endl;
                    ans = (ans + mod - one_time)%mod;
                }

                int two_time = (left * 1ll * (ff[nums[i]] * 1ll * rt)%mod)%mod;
                ans = (ans + mod - two_time)%mod;
            }

            // cout<< ans << endl;

            if(ft[nums[i]] > 0){
                for(auto &e: ft){
                    if(e.first == nums[i]) continue;
                    right = n - (i+1) - ft[nums[i]];
                    left = i - ff[nums[i]] - ff[e.first];
                    
                    int one_time = (ft[nums[i]] * 1ll * (e.second * 1ll * (left * 1ll * ff[e.first])%mod)%mod)%mod;
                    ans = (ans + mod - one_time)%mod;
                }

                int two_time = (ft[nums[i]] * 1ll * (lt * 1ll * right)%mod)%mod;
                ans = (ans + mod - two_time)%mod;
            }

            ff[nums[i]]++;
        }
        
        return ans;
    }
};
