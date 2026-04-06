class Solution {
public:
    long long solve(vector<int>& nums, int i, int skipped , vector<vector<long long>> &dp) {

        if (i >= nums.size() - 1)
            return 0;

        if (dp[i][skipped] != -1) return dp[i][skipped];

        long long take = 0;
        long long not_take = LLONG_MAX;

        take = max(0, max(nums[i - 1], nums[i + 1]) + 1 - nums[i]) + 
               solve(nums, i + 2, skipped , dp);

        if (skipped < 1) {
            not_take = solve(nums, i + 1, skipped + 1 , dp);
        }

        return dp[i][skipped] = 1LL*min(take , not_take);
    }

    long long minIncrease(vector<int>& nums) {

        int n = nums.size();

       if (n % 2) {
            long long ans = 0;
            for (int i = 1; i < n - 1; i += 2) {
                ans += max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
            }
            return ans;                    
        }

        vector<vector<long long>> dp(n, vector<long long >(2, -1));

        return solve(nums, 1, 0 , dp);
    }
};
