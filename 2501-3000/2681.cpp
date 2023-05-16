class Solution {
private:
    int mod = 1e9 + 7;
    
    int power(int x, int p) {
        int res = 1;
        while (p--) {
            res = (1LL * res * x) % mod;
        }
        return res;
    }
    
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), result = power(nums[n - 1], 3), factor = 0; // factor is f(i)
        for (int i = n - 2; i >= 0; i--) {
            factor = (2LL * factor + power(nums[i + 1], 2)) % mod; // f(i) = x[i + 1]^2 + 2f(i + 1)
            result = (result + power(nums[i], 3) + (1LL * nums[i] * factor) % mod) % mod; // x[i]^3 + x[i].f(i)
        }
        return result;
    }
};
