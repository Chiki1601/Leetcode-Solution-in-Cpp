class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>> dp(302, vector<int>(302));

        for (int i = nums.size() - 1; i >= 0; --i){
            int num = nums[i];
    
            for (int next = 1; next <= 300; ++next){
                int diff = abs(next - num);
                dp[num][diff] = max(dp[num][diff], dp[next][diff] + 1);
            }

            for (int j = 1; j <= 300; ++j){
                dp[num][j] = max(dp[num][j], dp[num][j - 1]);
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i <= 301; ++i){
            for (int j = 0; j <= 301; ++j){
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
