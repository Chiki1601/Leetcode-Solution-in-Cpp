class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long r = 0;
        int n = nums.size();
        int d = n / 3;
        for (int i = d; i < n; i += 2) {
            r += static_cast<long long>(nums[i]);
        }
        return r;
    }
};
