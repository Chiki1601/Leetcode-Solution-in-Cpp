class Solution {
public:
    // Function to check if there exist two numbers in the given array `nums`
    // such that their bitwise OR operation results in a number with trailing zeros.
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size(); // Number of elements in the array `nums`
        int i = 0; // Index variable for the outer loop
        
        // Iterate through the array with the outer loop
        while (i < n) {
            int j = 0; // Index variable for the inner loop
            
            // Iterate through the array with the inner loop
            while (j < n) {
                // Check if the indices are different and the bitwise OR of the elements
                // at these indices results in a number with trailing zeros (even number)
                if (i != j && (nums[i] | nums[j]) % 2 == 0) {
                    return true; // Return true if such a pair is found
                }
                j++; // Move to the next element in the inner loop
            }
            i++; // Move to the next element in the outer loop
        }
        
        return false; // Return false if no such pair is found
    }
};



