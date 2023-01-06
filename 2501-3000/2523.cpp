class Solution 
{
public:
    vector<int> closestPrimes(int left, int right) 
    {
        //marks all prime number from 2 to right using sieve algorithm
        vector<int> nums(right+1, 1);
        for(int i=2; i*i<=right; i++)
        {
            if(nums[i]==1)
            {
                for(int j=i*i; j<=right; j+=i)
                    nums[j]=0;
            }
        }

        //storing all prime number between left and right
        vector<int> prime;
        for(int i=max(2,left); i<=right; i++)
        {
            if(nums[i]==1) prime.push_back(i);
        }

        //finding pair of prime numbers having minimum difference
        int n1=-1, n2=-1, mini=1e8, diff;
        for(int i=1; i<prime.size(); i++)
        {
            diff = prime[i]-prime[i-1];
            if(diff < mini)
            {
                mini = diff;
                n1 = prime[i-1];
                n2 = prime[i];
            }
        }
        return {n1, n2};
    }
};
