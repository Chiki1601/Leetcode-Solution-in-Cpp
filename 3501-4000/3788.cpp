class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        int min[n];
        min[n - 1] = nums[n - 1];
        for(int i = n - 2; i > 0; i--) {
            min[i] = fmin(min[i + 1], nums[i]);
        }
        long long ans = nums[0] - min[1], prefix_sum = nums[0];
        for(int i = 1; i < n - 1; i++) {
            prefix_sum += nums[i];
            ans = fmax(ans, prefix_sum - min[i + 1]);
        }
        return ans;
    }
};
