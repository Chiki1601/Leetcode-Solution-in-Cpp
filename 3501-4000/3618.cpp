class Solution {
private:
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0)
                return false;
        }
        
        return true;
    }
    
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> primes(n, false);
        
        long long sumA = 0, sumB = 0 ;
        
        for (uint i = 0; i < n; ++i) {
            if (isPrime(i))
                sumA += nums[i];
            else
                sumB += nums[i];
        }
        
        return fabs(sumA - sumB);
    }
};
