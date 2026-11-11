#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
struct Pow{
    ll mod,base;
    vector<ll> pw;
    Pow(ll mod_,ll base_,int n):mod(mod_),base(base_){
        pw.assign(n+1,1);
        for(int i=1;i<=n;++i)pw[i]=pw[i-1]*base%mod;
    }
    ll modpow(ll a,ll e){
        ll r=1%mod;a%=mod;
        while(e){if(e&1)r=r*a%mod;a=a*a%mod;e>>=1;}
        return r;
    }
    ll inv(ll x){return modpow(x,mod-2);}
    ll get(int i){return pw[i];}
};
struct SegHash{
    int V;
    ll mod,base,invBm1;
    vector<int> cnt;
    vector<ll> h,pw;
    SegHash(int V_,int n,ll mod_,ll base_):V(V_),mod(mod_),base(base_){
        cnt.assign(4*V+5,0);
        h.assign(4*V+5,0);
        Pow p(mod,base,n+1);
        pw=p.pw;
        invBm1=p.inv(base-1);
    }
    ll leafHash(ll v,ll c){
        if(!c)return 0;
        return ((v+1)%mod)*((pw[c]-1+mod)%mod)%mod*invBm1%mod;
    }
    void pull(int node){
        int lc=node*2,rc=node*2+1;
        h[node]=(h[rc]*pw[cnt[lc]]+h[lc])%mod;
        cnt[node]=cnt[lc]+cnt[rc];
    }
    void update(int node,int l,int r,int pos,ll v){
        if(l==r){cnt[node]++;h[node]=leafHash(v,cnt[node]);return;}
        int mid=(l+r)/2;
        if(pos<=mid)update(node*2,l,mid,pos,v);
        else update(node*2+1,mid+1,r,pos,v);
        pull(node);
    }
    void insert(ll v){update(1,1,V,(int)v,v);}
    ll getHash(){return h[1];}
};
class Solution{
public:
    vector<int> countSuffix(vector<int>& nums,vector<int>& target){
        int n=nums.size(),m=target.size(),maxV=1;
        for(int x:nums)maxV=max(maxV,x);
        for(int x:target)maxV=max(maxV,x);
        ll mod1=1000000007,mod2=998244353,base1=911382323,base2=972663749;
        Pow p1(mod1,base1,m),p2(mod2,base2,m);
        vector<ll> t1(m+1,0),t2(m+1,0),n1(n+1,0),n2(n+1,0);
        for(int i=0;i<m;++i){
            t1[i+1]=(t1[i]*base1+target[i]+1)%mod1;
            t2[i+1]=(t2[i]*base2+target[i]+1)%mod2;
        }
        for(int i=0;i<n;++i){
            n1[i+1]=(n1[i]*base1+nums[i]+1)%mod1;
            n2[i+1]=(n2[i]*base2+nums[i]+1)%mod2;
        }
        SegHash s1t(maxV,n,mod1,base1),s2t(maxV,n,mod2,base2);
        map<pair<ll,ll>,int> bucket;
        for(int i=n-1;i>=0;--i){
            s1t.insert(nums[i]);s2t.insert(nums[i]);
            ll sh1=s1t.getHash(),sh2=s2t.getHash();
            int len=n-i;
            ll full1=(n1[i]*p1.modpow(base1,len)+sh1)%mod1;
            ll full2=(n2[i]*p2.modpow(base2,len)+sh2)%mod2;
            bucket[{full1,full2}]++;
        }
        vector<int> ans(m-n+1,0);
        for(int k=0;k<=m-n;++k){
            ll h1=(t1[k+n]-t1[k]*p1.get(n))%mod1;
            ll h2=(t2[k+n]-t2[k]*p2.get(n))%mod2;
            if(h1<0)h1+=mod1;
            if(h2<0)h2+=mod2;
            auto it=bucket.find({h1,h2});
            if(it!=bucket.end())ans[k]=it->second;
        }
        return ans;
    }
};
