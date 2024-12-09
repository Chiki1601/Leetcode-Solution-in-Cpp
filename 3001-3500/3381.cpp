class Solution
{
public:
    long maxSubarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();

        // Step 1: Create prefix sum array
        vector<long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) 
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Step 2: Initialize array to track minimum prefix sums for each remainder
        vector<long> minPrefixSum(k, LLONG_MAX);

        // Step 3: Initialize maxSum to track the result
        long maxSum = LLONG_MIN;

        // Step 4: Iterate over the prefix sum array
        for (int i = 0; i <= n; ++i) 
        {
            int remainder = i % k;

            // Step 5: If i >= k, calculate the maximum subarray sum
            if (i >= k) 
            {
                maxSum = max(maxSum, prefixSum[i] - minPrefixSum[remainder]);
            }

            // Step 6: Update the minimum prefix sum for the current remainder
            minPrefixSum[remainder] = min(minPrefixSum[remainder], prefixSum[i]);
        }

        // Step 7: Return the result (0 if no valid subarray is found)
        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};
