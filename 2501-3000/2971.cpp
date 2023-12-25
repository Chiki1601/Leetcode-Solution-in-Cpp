
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0; // Initialize a variable to store the sum of all elements
        sort(nums.begin(), nums.end()); // Sort the elements in non-decreasing order

        // Calculate the sum of all elements in the input vector
        for (auto i : nums) {
            sum += i;
        }

        int n = nums.size(); // Get the size of the input vector

        // Loop through the sorted vector from the end to find the largest perimeter
        for (int i = n - 1; i >= 2; i--) {
            sum -= nums[i]; // Remove the largest element from the sum
            // Check if the sum of two smaller sides is greater than the largest side
            if (sum > nums[i]) {
                return sum + nums[i]; // If true, return the largest perimeter
            }
        }

        return -1; // If no valid triangle is possible, return -1
    }
};


