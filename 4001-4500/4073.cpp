class Solution {
public:
    int countGoodStrings(long long n) {
        if(n ==0)
        {
            return 0;
        }
        long long mod= 1e9+7;
        auto multiply = [&] (const vector<vector<long long>>& A, const vector<vector<long long>>& B)
        {
            vector<vector<long long>>C(2, vector<long long>(2,0));
            for(int i =0; i<2;++i)
            {
                for(int j =0; j<2; ++j)
                {
                    for(int k=0; k<2;++k)
                    {
                        C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
                    }
                }
            }
            return C;
        };
        vector<vector<long long>>T = {{1,1},{1,0}};
        vector<vector<long long>>res = {{1,0},{0,1}};
        long long p = n-1;
        while(p>0)
        {
            if(p&1)res=multiply(res,T);
            T=multiply(T,T);
            p>>=1;
        }
        long long fib = res[0][0];
        return (2*fib)%mod;
    }
};
