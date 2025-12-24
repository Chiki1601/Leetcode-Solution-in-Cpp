class Solution {
public:
    long long lastInteger(long long n) {
        long long mask = 0;
        for(int i = 1; i < 63; i += 2) mask |= (1LL << i);
        return 1 + (mask & (n - 1)); 
    }
};
