class Solution {
public:
    int solve(vector<int>&nums, vector<vector<int>>&trimmedLen, vector<int>&dp, int& k, int start) //Partition DP
    {
        if (start >= nums.size()) return 0;
        if (dp[start] != -1) return dp[start];
        
        int minAns = INT_MAX;
        for (int end = start; end < nums.size(); end++)
        {
            int curr = k + trimmedLen[start][end];
            int nextMin = solve(nums, trimmedLen, dp, k, end + 1);
            int total = curr + nextMin;
            minAns = min(minAns, total);
        }
        return dp[start] = minAns;
    }
    int minCost(vector<int>& nums, int k) 
    {
        int n = nums.size();
        //==========================================================================================
        //CALCULATING "TRIMMED LEN" OF ALL SUBAARAYS IN O(N^2) INSTEAD OF O(N^3)
        //trimmedLen[i][j] gives trimmed length of subarray from (i to j)
        vector<vector<int>>trimmedLen(n, vector<int>(n, 0)); 
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            vector<int>mp(1001, 0);
            for (int j = i; j < n; j++)
            {
                int num = nums[j];
                if (mp[num] != 0) //if the current num already exist in map then only increment "count"
                {
                    if (mp[num] == 1) count += 2; //whenever the freq goes from 1 to 2 (add 2 to the count)
                    else count++; 
                }
                mp[num]++;
                trimmedLen[i][j] = count;
            }
        }
        //=============================================================================================
        vector<int>dp(n, -1);
        return  solve(nums, trimmedLen, dp, k, 0);
        
    }
};
