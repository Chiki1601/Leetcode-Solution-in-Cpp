class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        if (nums.size() < 2) return 0LL;
        long long a = 0, b = 0;
        for (int x : nums) {
            long long v = std::llabs((long long)x);
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return 100000LL * a * b;
    }
};
