class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX; 
        bool found = false;

        for (int len = l; len <= r; ++len) {
            int currentSum = 0;

            for (int i = 0; i < len; ++i) {
                currentSum += nums[i];
            }

            if (currentSum > 0) {
                minSum = min(minSum, currentSum);
                found = true;
            }

            for (int i = len; i < n; ++i) {
                currentSum += nums[i] - nums[i - len]; 

                if (currentSum > 0) {
                    minSum = min(minSum, currentSum);
                    found = true;
                }
            }
        }

        return found ? minSum : -1; 
    }
};
