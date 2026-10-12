class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> prime(n+1,true);
        vector<int>res;
        long long sum =0;
        for(int x=2; x<=n;++x)
        {
            if(!prime[x])
            {
                continue;
            }
            if(sum+x>s)
            {
                break;
            }
            sum+=x;
            res.push_back(x);
            for(long long i = (long long)x*x;i<=n;i+=x)
            {
                prime[i]=false;
            }
        }
        return res;
    }
};
