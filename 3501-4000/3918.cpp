class Solution {
    bool isPrime(int num)
    {
        if(num == 1)
            return false;
        for(int i = 2; i <= sqrt(num); ++i)
            if(num%i == 0)
                return false;
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        if(n < 10 && isPrime(n) == false)
            return 0;
        if(n < 10 && isPrime(n) == true)
            return n;
        int rev = 0, rem = 0, tmp = n;
        while(tmp > 0)
        {
            rem = tmp%10;
            rev = rev*10 + rem;
            tmp /= 10;
        }
        int sum = 0;
        for(int i = min(n, rev); i <= max(n, rev); ++i)
            if(isPrime(i))
                sum += i;
        return sum;
    }
};
