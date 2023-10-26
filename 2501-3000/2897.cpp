class Solution {
public:
    typedef long long ll;
    int maxSum(vector<int>& nums, int k) {
        vector<ll> c(32, 0); // count set bits
        ll res = 0, mod = 1e9 + 7;
        
        for (int i = 0; i < 31; i++) {
            for (int num : nums) {
                if (num & (1 << i)) {
                    c[i]++;
                }
            }
        }
        
        for (int j = 1; j <= k; j++) {
            ll x = 0; // form the maximum number with the available bit counts
            for (int i = 0; i < 31; i++) {
                if (c[i] > 0) {
                    x |= (1 << i);
                    c[i]--;
                } 
            } 
            res += (x * x);
            res %= mod;
        }
        
        return res;
    }
};
