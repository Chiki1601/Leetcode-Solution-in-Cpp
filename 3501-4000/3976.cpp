class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long kadane = 0,sum = 0;
        for(auto &it : nums){
            if(sum<0)sum = 0;
            sum += 1LL * it;
            kadane = max(kadane,sum);
        }
        if(kadane>0)return k * kadane;
        sort(nums.begin(),nums.end(),greater());
        return ceil(nums[0]/k);
    }
};
