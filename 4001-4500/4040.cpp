class Solution {
public:
    int solve(vector<int>& nums,int i,int sum,vector<vector<int>>& dp){
        if(sum==0) return 0;                 //base case
        if(i>=nums.size()) return INT_MAX;  //base case
        if(sum<0) return INT_MAX;           //base case
        if(dp[i][sum]!=-1) return dp[i][sum]; ///base case
        int ans=INT_MAX;
        ans=min(ans,solve(nums,i+1,sum,dp)); // skip case
        int val=nums[i];     // Just storing in val
        int opp=0;  // no of opp 
        while(val){     // first dividing till val !=0 and exploare the all the case
            val/=2; 
            opp++;
            int rr=solve(nums,i+1,sum-val,dp); // explore
            if(rr!=INT_MAX) rr=rr+opp; // edge case if rr!=INT_MAX;
             ans=min(ans,rr);
        }
        val=nums[i];  // RE ASSGINE VALUES FOR THE MULTIPLICATION
        opp=0; // reset to 0 
        while(val<=5000){  // multiply till the value<= 5000 and explore
            int rr=solve(nums,i+1,sum-val,dp); // explore
            if(rr!=INT_MAX) rr=rr+opp; //edge case
            ans=min(ans,rr);
            opp++; 
            val=val*2; 
        }
        return dp[i][sum]=ans; /// from all choose the best one
    }
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
       vector<vector<int>> dp(n+1,vector<int>(5002,-1));
        int ans=solve(nums,0,sum,dp);
        if(ans==INT_MAX) return -1;// -1 case 
        return ans;
    }
};
