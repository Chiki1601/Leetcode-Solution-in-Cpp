class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1); // dp[i] represents the maximum jumps from index 0 to index i
        
        dp[0] = 0; // Starting index
        
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= max(0, i - target); j--) {
                if (nums[j] >= nums[i] - target && nums[j] <= nums[i] + target) {
                    if (dp[j] != -1) {
                        if (dp[i] == -1) {
                            dp[i] = dp[j] + 1;
                        }
                        else {
                            dp[i] = min(dp[i], dp[j] + 1);
                        }
                    }
                }
            }
        }
        
        return dp[n - 1] == -1 ? -1 : dp[n - 1];
    }
};
