class Solution {
public:
    long long countInterestingSubarrays(vector<int>& v, int mod, int k) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]%mod==k)
                v[i]=1;
            else
                v[i]=0;
        }
        map<int,long long>m;
        int p=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            p=(p+v[i])%mod;
            if(p==k)
                ans++;
            int rem=p-k;
            if(rem<0)
                rem=rem+mod;
            ans=ans+m[rem];
            m[p]++;
        }
        return ans;
    }
};
