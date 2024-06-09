class Solution {
public:
    int ans;
    int solve(int i,int n,int r,vector<int>&v,vector<vector<int>>&dp) {
        if(i==n) {
            return r;
        }
        if(dp[i][r]!=-1)
            return dp[i][r];
        int include=r;
        if(v[i]>r) {
            include=solve(i+1,n,r+v[i],v,dp);
        }
        int exclude=solve(i+1,n,r,v,dp);
        return dp[i][r]=max(include,exclude);
    }
    int maxTotalReward(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>dp(2001,vector<int>(4001,-1));
        ans=solve(0,n,0,v,dp);
        return ans;
    }
};
