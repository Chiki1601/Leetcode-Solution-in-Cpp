class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n%2!=0)
        {
            return false;
        }
        int target = n/2;
        long long a=1,b=1;
        if(target==a)
        {
            return true;
        }
        while(b<target)
        {
            long long c=a+b;
            a=b;
            b=c;
            if(b==target)
            {
                return true;
            }
        }
        return false;
    }
};
