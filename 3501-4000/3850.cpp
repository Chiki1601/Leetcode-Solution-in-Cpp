class Solution {
public:
       unordered_map <string, int> dp;
    int solve(vector<int>& nums, long long k, int i, int c2, int c3, int c5){
        if(i >= nums.size()){
            if(c2 >= 0 && c3 >= 0 && c5 >= 0 && (k == pow(2, c2) * pow(3, c3) * pow(5, c5))){  // Final value of val will be accumulation of each factors counts. Also if any of the count is negative then it won't result in a integer value and hence invalid value.
                return 1;
            }
            return 0;
        }
        string key = to_string(i) + "#" +  to_string(c2) + "#" + to_string(c3) + "#" + to_string(c5);
        if(dp.find(key) != dp.end()) return dp[key];

        int tc2 = (nums[i] == 4)?1:0, tc3 = 0, tc5 = (nums[i] == 5)?1:0;
        if(nums[i] % 2 == 0) tc2 ++;
        if(nums[i] % 3 == 0) tc3++;

        int ans = solve(nums, k, i+1, c2, c3, c5);              // skip
        ans += solve(nums, k, i+1, c2+tc2, c3 + tc3, c5 + tc5); // consider for multiplication
        ans += solve(nums, k, i+1, c2-tc2, c3 - tc3, c5 - tc5); // consider for division
        
        return  dp[key] = ans;
    }
    
    int countSequences(vector<int>& nums, long long k) {    
        return solve(nums, k, 0, 0, 0, 0);
    }
};
