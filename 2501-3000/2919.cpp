class Solution {
public:
    int n; 
    vector<long long> dp;
    long long solve(int ind,vector<int>& nums, int k)
    {
        if(ind>n-3)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        //option 1
        long long op1 = max(0,k-nums[ind]) + solve(ind+1,nums,k);
        //option 2
        long long op2 = max(0,k-nums[ind+1]) + solve(ind+2,nums,k);
        //option 3
        long long op3 = max(0,k-nums[ind+2]) + solve(ind+3,nums,k);
        
        return dp[ind] = min(op1,min(op2,op3));
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n,-1);
        return solve(0,nums,k);
    }
};
