class Solution {
public:
    long long minCost(vector<int>& a, int x) {
        long long ans = 0;
        long long n = a.size();
        vector<long long> mi(n,1e9);
        for(int i=0;i<n;i++)
        {
            mi[i] = a[i];
            ans+=mi[i];
        }
        for(long long i=1;i<n;i++)
        {
            long long f = x;
            long long cost = i*f;
            for(long long j=0;j<n;j++)
            {
                long long d = a[(j+i)%n];
                mi[j] = min(mi[j],d);
                cost+=mi[j];
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};
