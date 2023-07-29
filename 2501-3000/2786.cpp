using ll = long long;
class Solution {
public:
    ll func(int idx, vector<int> &nums, int x, int prev, vector<vector<ll>> &dp)
    {
        if (idx == nums.size())
            return 0;
        ll pick = -1e12, notpick = -1e12;
        // Pick 
        if (dp[idx][prev] != -1)
            return dp[idx][prev];
        if (nums[idx] % 2 != 0)
        {
            if (prev)
                pick = nums[idx] + func(idx + 1, nums, x, (nums[idx] % 2 != 0), dp);
            else
                pick = nums[idx] - x + func(idx + 1, nums, x, (nums[idx] % 2 != 0), dp);
        }
        else
        {
            if (prev == 0)
                pick = nums[idx] + func(idx + 1, nums, x, (nums[idx] % 2 != 0), dp);
            else
                pick = nums[idx] - x + func(idx + 1, nums, x, (nums[idx] % 2 != 0), dp);
        }
        notpick = 0 + func(idx + 1, nums, x, prev, dp);
        
        return dp[idx][prev] = max(notpick, pick);
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<ll>> dp(nums.size() + 1, vector<ll> (2, -1));
        return func(0, nums, x, (nums[0] % 2 == 1), dp);
    }
};
