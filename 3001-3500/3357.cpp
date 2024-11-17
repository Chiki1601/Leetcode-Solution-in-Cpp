class Solution {
public:
    // Helper function to check if a given maxDiff is feasible
    bool isValidDifference(vector<int> nums, int maxDiff) {
        vector<int> lowerBounds, upperBounds;

        // Traverse through the nums array
        for (int i = 0; i < nums.size(); i++) {
            // When an element is not -1 and is adjacent to a -1, compute possible values
            if (nums[i] != -1 && (i && nums[i-1] == -1 || (i != nums.size()-1) && nums[i+1] == -1)) {
                lowerBounds.push_back(nums[i] - maxDiff);  // Minimum possible value for the element
                upperBounds.push_back(nums[i] + maxDiff);  // Maximum possible value for the element
            }
        }

        // Calculate the minimum and maximum values considering the allowed difference
        int minValue = *min_element(lowerBounds.begin(), lowerBounds.end()) + 2 * maxDiff;  // The lower bound value
        int maxValue = *max_element(upperBounds.begin(), upperBounds.end()) - 2 * maxDiff;  // The upper bound value

        // Now, for each -1 in the array, try to fill it with either `minValue` or `maxValue`
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) {  // If it's a missing value
                // Try replacing with `minValue` first
                if (
                    (i == 0 || abs(nums[i-1] - minValue) <= maxDiff) &&  // Check left neighbor
                    (i == (nums.size() - 1) || nums[i+1] == -1 || abs(nums[i+1] - minValue) <= maxDiff))  // Check right neighbor
                {
                    nums[i] = minValue;  // Replace with `minValue`
                } else {
                    nums[i] = maxValue;  // Otherwise, replace with `maxValue`
                }
            }
        }

        // After replacing all -1 values, check if the difference between adjacent elements is within `maxDiff`
        for (int i = 0; i < nums.size()-1; i++) {
            if (abs(nums[i] - nums[i+1]) > maxDiff) {  // If any difference exceeds `maxDiff`, return false
                return false;
            }
        }

        // If no differences exceeded the allowed maxDiff, return true
        return true;
    }

    // Main function to find the minimum possible difference between adjacent elements
    int minDifference(vector<int>& nums) {    
        int missingCount = 0;

        // Count how many missing values (-1) are in the array
        for (int x: nums) if (x == -1) missingCount++;

        // If no missing values, calculate the maximum difference between adjacent elements
        if (missingCount == 0) {
            int maxDiff = 0;
            for (int i = 0; i < nums.size()-1; i++) {
                maxDiff = max(maxDiff, abs(nums[i] - nums[i+1]));  // Find the largest difference
            }
            return maxDiff;
        } 
        // If all elements are missing, the minimum difference is 0 since we can set them to the same value
        else if (missingCount == nums.size()) return 0;

        // Perform binary search to find the minimum possible `maxDiff`
        int low = 0;
        int high = 1000000005;  // A large enough number to represent the upper bound

        // Binary search for the minimum `maxDiff`
        while (low != high) {
            int mid = (low + high) / 2;  // Find the midpoint of the current range

            // Test if the current maxDiff is feasible
            if (isValidDifference(nums, mid)) {
                high = mid;  // If feasible, try a smaller `maxDiff`
            } else {
                low = mid + 1;  // If not feasible, try a larger `maxDiff`
            }
        }

        // Return the smallest `maxDiff` that worked
        return low;
    }
};
