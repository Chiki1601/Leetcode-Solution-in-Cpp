class Solution {
public:
    int check(int n)
    {
        int sum = 0;
        int temp = n;
         if(n%2==0)
        {
            while(n%2==0)
            {
                sum+=2;
                n/=2;
            }
        }
        for(int i = 3;i<=sqrt(n);i+=2)
        {
           if(n%i==0)
            {
                while(n%i==0)
                {
                    sum+=i;
                    n/=i;
                }
            }
        }
        // cout<<sum<<" "<<n<<endl;
        if(n>1)
        sum+=n;
        if(sum>=temp)sum = 0;
        return sum;
    }
    int smallestValue(int n) {
        int X = 1e5;
        vector<int>v;
        vector<bool>isPrime(X+1,0);
        for(int i=2;i*i<=X;i++)
        {
            if(isPrime[i]==false)
            {
                v.push_back(i);
                for(int j=2*i;j<=X;j+=i)
                {
                    isPrime[j] = true;
                }
            }
         }
        unordered_map<int,int>mp;
        while(1)
        {
            int ans = check(n);
            if(ans==0)break;
            n = ans;
            
        }
        return n;
    }
};
