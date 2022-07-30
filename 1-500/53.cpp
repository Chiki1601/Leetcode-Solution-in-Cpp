class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int max_sum_so_far = 0;

        for(int i = 0; i < nums.size(); i++){
            max_sum_so_far += nums[i];

            if(max_sum < max_sum_so_far){
                max_sum = max_sum_so_far;
            }

            if(max_sum_so_far < 0){
                max_sum_so_far = 0;
            }
        }

        return max_sum;
    }
};
