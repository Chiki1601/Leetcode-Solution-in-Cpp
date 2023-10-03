class Solution {
public:
    long long maximumTripletValue(vector<int>& v) {
        long long ans=0;
        int n=v.size();
        vector<int>l(n,0);
        vector<int>r(n,0);
        int s=v[0];
        for(int i=1;i<n;i++)
        {
            l[i]=s;
            s=max(s,v[i]);
        }
        s=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            r[i]=s;
            s=max(s,v[i]);
        }
        for(int i=1;i<n-1;i++)
        {
            long long k=(long long)(l[i]-v[i])*r[i];
            ans=max(ans,k);
        }
        return ans;
    }
};
