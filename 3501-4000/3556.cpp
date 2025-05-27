class Solution {
private:
    bool isPrime(long long n){
        if (n <= 1)
            return false;
        else if (n <= 3)
            return true;
        else if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (long long i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
public:
    long long sumOfLargestPrimes(string s) {
        int n = s.length();
        long long first = 0, second = 0, third = 0;
        for (int i = 0; i < n; i++){
            for (int len = 1; len <= n - i; len++){
                long long num = stol(s.substr(i, len));
                if (isPrime(num) && num != first && num != second && num != third){
                    if (num > first){
                        third = second;
                        second = first;
                        first = num;
                    }
                    else if (num > second){
                        third = second;
                        second = num;
                    }
                    else if (num > third)
                        third = num;
                }
            }
        }
        return first + second + third;
    }
};
