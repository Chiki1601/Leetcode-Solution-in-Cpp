class Solution {
public:
    vector<vector<int>> dp;
    
int solve(vector<int>& nums, int i, int last){
    if(i+1 >= nums.size()) return max(nums[last], (i < nums.size()?nums[i]:0));
    if(dp[i][last] != -1) return dp[i][last];
    int res = max(nums[i], nums[i+1]) + solve(nums, i+2,  last);
        res = min(res, max(nums[i],  nums[last]) + solve(nums, i+2, i+1));
        res = min(res, max(nums[i+1],  nums[last]) + solve(nums, i+2, i));
    return dp[i][last] = res;
}

int minCost(vector<int>& nums) {
    dp.resize(1001, vector<int>(1001, -1));
    return solve(nums, 1, 0);
}
   
};
