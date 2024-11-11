class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size(), ans = 0, left = 0, right = 0;
        sort(nums.begin(), nums.end());  // Sort the array for sliding window approach

        // HashMap to store frequency of each number
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        // First pass: choose an existing number as the reference point
        for (int mid = 0; mid < n; mid++) {
            // Adjust left pointer to keep nums[mid] - nums[left] within `k`
            while (nums[mid] - nums[left] > k) {
                left++;
            }

            // Adjust right pointer to keep nums[right] - nums[mid] within `k`
            while (right < n - 1 && nums[right + 1] - nums[mid] <= k) {
                right++;
            }

            int total = right - left + 1;  // Calculate range size
            // Update ans with maximum achievable frequency for nums[mid] as the target
            ans = max(ans, min(total - count[nums[mid]], numOperations) + count[nums[mid]]);
        }

        // Second pass: choose a non-existent number as reference point
        left = 0;
        for (right = 0; right < n; right++) {
            int mid = (nums[left] + nums[right]) / 2;  // Calculate hypothetical midpoint

            // Adjust left pointer to ensure midpoint is within `k` range from both ends
            while (mid - nums[left] > k || nums[right] - mid > k) {
                left++;
                mid = (nums[left] + nums[right]) / 2;
            }

            // Update ans with maximum achievable frequency with the hypothetical midpoint
            ans = max(ans, min(right - left + 1, numOperations));
        }

        return ans;
    }
}
