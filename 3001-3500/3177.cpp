int dp[5000][51];
class Solution {
public:
int maximumLength(vector<int>& nums, int k) {
    int res = 0, max_dp[51] = {};
    unordered_map<int, int> prev;
    for (int i = nums.size() - 1; i >= 0; --i) {
        auto it = prev.find(nums[i]);
        int p = it != end(prev) ? it->second : i;
        for (int j = k; j >= 0; --j) {
            dp[i][j] = max(
                1 + (i != p ? dp[p][j] : 0),
                1 + (j ? max_dp[j - 1] : 0));
            max_dp[j] = max(max_dp[j], dp[i][j]);  
        }     
        prev[nums[i]] = i;
        res = max(res, dp[i][k]);
    } 
    return res;
}
};
