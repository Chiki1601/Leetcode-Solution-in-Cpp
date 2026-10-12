class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        if(n<2||s<2)
        {
            return {};
        }
        int lim = min(n,s);
        vector<bool> prime(lim+1, true);
        vector<int> prime1;
        prime[0]=prime[1]=false;
        for(int x=2;x*x<=lim;++x)
        {
            if(prime[x])
            {
                for(int i = x*x; i<=lim;i+=x)
                {
                    prime[i]=false;
                }
            }
        }
        for(int x=2; x<=lim;++x)
        {
            if(prime[x]) prime1.push_back(x);
        }
        if(prime1.empty())
        {
            return {};
        }
        int m = prime1.size();
        const unsigned short INF = 65535;
        vector<vector<unsigned short>> dp(m+1,vector<unsigned short>(s+1,INF));
        dp[m][0]=0;
        for(int i =m-1;i>=0;--i)
        {
            int p = prime1[i];
            dp[i]=dp[i+1];
            for(int v=p;v<=s;++v)
            {
                if(dp[i+1][v-p]!= INF && dp[i+1][v-p]+1<dp[i][v])
                {
                    dp[i][v]=dp[i+1][v-p]+1;
                }
            }
        }
            int best_sum=-1;
            for(int v=s;v>=1;--v)
            {
                if(dp[0][v]!=INF)
                {
                    best_sum=v;
                    break; 
                }
            }
            if(best_sum==-1)
            {
                return {};
            }
            int min_count = dp[0][best_sum];
            vector<int> best_subset;
            int v= best_sum,c=min_count,i=0;
            while(v>0)
            {
                for(int j =i;j<m;++j)
                {
                    int p = prime1[j];
                    if(p>v) break;
                    if(dp[j+1][v-p]==c-1)
                    {
                        best_subset.push_back(p);
                        v-=p;
                        --c;
                        i=j+1;
                        break;
                    }
                }
            }
            return best_subset;
        
    }
};
