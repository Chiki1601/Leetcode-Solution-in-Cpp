class Solution {
   public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);
            ++diff[start];
            --diff[i + 1];
        }
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];
        }
        int subSum = 0;
        for (int i = 0; i < n; ++i) {
            subSum += nums[i] * diff[i];
        }
        return subSum;
    }
};
