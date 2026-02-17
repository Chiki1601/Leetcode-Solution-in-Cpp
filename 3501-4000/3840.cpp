class Solution {
public:
    long long solve(vector<long long> &dp,vector<int> &nums,vector<int> &colors,int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=solve(dp,nums,colors,i+1);
        if(i+1==nums.size() || colors[i]!=colors[i+1])
        ans=max(ans,solve(dp,nums,colors,i+1)+nums[i]);
        if(i+1<nums.size() && colors[i]==colors[i+1])
        ans=max(ans,solve(dp,nums,colors,i+2)+nums[i]);
        return dp[i]=ans;
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long> dp(n,-1);
        return solve(dp,nums,colors,0);
    }
};
