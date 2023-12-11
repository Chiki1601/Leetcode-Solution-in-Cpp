class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans; // Resultant vector to store good indices
        int k = 0; // Counter for keeping track of the index

        for (const auto& x : variables) { // Loop through the 'variables' vector
            int m = x[0], b = x[1], c = x[2], d = x[3]; // Extracting values from subarray

            int n1 = 1; // Initialize n1

            // Calculate (m ^ b) % 10
            for (int i = 0; i < b; ++i) {
                n1 = (n1 * m) % 10;
            }

            int n2 = 1; // Initialize n2

            // Calculate (n1 ^ c) % d
            for (int i = 0; i < c; ++i) {
                n2 = (n2 * n1) % d;
            }

            // Check if n2 matches the target
            if (n2 == target) {
                ans.push_back(k); // If true, push index 'k' into the answer vector
            }

            k++; // Increment the index counter
        }

        return ans; // Return the resulting vector containing good indices
    }
};

