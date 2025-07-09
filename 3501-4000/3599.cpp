int dp[251][251];
class Solution {
public:
    int minXor(vector<int>& nums, int k, int i = 0) {
        if (i == 0)
            memset(dp, -1, sizeof(dp));
        if (i == nums.size())
            return 0;
        if (nums.size() - i < k || k <= 0)
           return INT_MAX;            
        if (dp[i][k] < 0) {
            int x = 0, res = INT_MAX;
            for (int j = i; j + k - 1 < nums.size(); ++j) {
                x ^= nums[j];
                if (x < res)
                    res = min(res, max(x, minXor(nums, k - 1, j + 1)));
            }
            dp[i][k] = res;
        }
        return dp[i][k];
    }
};
