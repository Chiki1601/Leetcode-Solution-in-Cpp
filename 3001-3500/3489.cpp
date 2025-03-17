class Solution {
public:
   int solve(vector<vector<int>>& q, int i, int target, int k, vector<vector<int>>& dp){
    if(target == 0) return k;                                            // we found  a valid sum equal to target so return current index of query.
    if(k >= q.size() || target < 0) return q.size() + 1;    // return a larger number to invalidate this flow
    if(dp[target][k] != -1) return dp[target][k];
    int res = solve(q, i, target, k+1, dp);     //skip current query val
    if(q[k][0] <= i && i <= q[k][1]) res = min(res, solve(q, i, target - q[k][2], k+1, dp));   // pick the val if its range is in the range of target index
    return dp[target][k] = res;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int ans = -1;
    for(int i = 0; i < nums.size(); ++i){
        vector<vector<int>> dp(nums[i]+1, vector<int>(queries.size() +1, -1));
        ans = max(ans, solve(queries, i, nums[i], 0, dp));
    }
    return (ans > queries.size())?-1: ans;
}
};
