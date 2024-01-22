class Solution {
public:
    // Function to find the minimum number of key presses needed to type a given string
    int minimumPushes(string word) {
        // Initialize variables to store the result, the size of the word, and the current row
        int ans = 0, n = word.size(), row = 1;

        // Calculate the quotient and remainder when dividing the length of the string by 8
        int quotient = n / 8;
        int remainder = n % 8;

        // Iterate over complete cycles (quotient)
        while (quotient--) {
            // Add the product of 8 (number of keys in a cycle) and the current row to the result
            ans += 8 * row;
            
            // Increment the row for the next cycle
            row++;
        }

        // Add the product of the remainder and the final row to account for remaining letters
        ans += remainder * row;

        // Return the final result, representing the minimum number of key presses
        return ans;
    }
};
