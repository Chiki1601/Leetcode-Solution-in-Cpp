class Solution {
public:
    int mod = 1e9+7;
    
    long long solve(long long ind ,long long n ,int num , int x,vector<vector<long long>>& dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(ind == num+1) return 0;

        if(dp[ind][n] != -1) return dp[ind][n];

        long long nonpick = solve(ind+1,n,num,x,dp)%mod;
        long long pick = solve(ind+1,n-pow(ind,x),num,x,dp)%mod;

        return dp[ind][n] = (pick + nonpick)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        return solve(1,n,n,x,dp);
    }
};
