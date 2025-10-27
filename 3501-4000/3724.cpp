class Solution {
public:
    // Function to calculate minimum operations to equalize two arrays
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long totalCost = 0;

        // Step 1: Compute the base cost (sum of absolute differences)
        for (int i = 0; i < n; i++) {
            totalCost += abs(nums1[i] - nums2[i]);
        }

        // Step 2: Pick a reference value from nums2 (last element)
        long long referenceValue = nums2[n-1];
        long long minAdjustment = LLONG_MAX;

        // Step 3: Find minimal adjustment using the reference value
        for (int i = 0; i < n; i++) {
            if ((referenceValue >= nums1[i] && referenceValue <= nums2[i]) ||
                (referenceValue >= nums2[i] && referenceValue <= nums1[i])) {
                // No adjustment needed if reference lies between nums1[i] and nums2[i]
                minAdjustment = 0;
            } else {
                // Otherwise, find the minimal distance to either nums1[i] or nums2[i]
                minAdjustment = min({
                    minAdjustment,
                    abs(nums1[i] - referenceValue),
                    abs(nums2[i] - referenceValue)
                });
            }
        }

        // Step 4: Return the total cost including the minimal adjustment
        return totalCost + minAdjustment;
    }
};
