class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() == 0) return vector<int>();
        sort(nums.rbegin(), nums.rend());

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curSum = 0;
        int i = 0;
        vector<int> ans;

        while(curSum <= sum/2.0){
            ans.push_back(nums[i]);
            curSum += nums[i];
            i++;
        }

        return ans;
    }
};
