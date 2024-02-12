class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        // Get the number of rows (m) and columns (n) in the matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Create a new matrix "ans" filled with zeros
        vector<vector<int>> ans(m, vector<int>(n, 0));

        // Create a vector "col" to store maximum elements in each column, initially filled with -1
        vector<int> col(n, -1);

        // Step 1: Iterate through each column of the matrix
        for (int i = 0; i < n; i++) {
            // Step 2: Iterate through each row of the matrix
            for (int j = 0; j < m; j++) {
                // Step 3: Copy elements from the original matrix to the "ans" matrix
                ans[j][i] = matrix[j][i];
                
                // Update the "col" vector with the maximum element in the current column
                col[i] = max(col[i], matrix[j][i]);
            }
        }

        // Step 4: Iterate through each element in the "ans" matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Step 5: If the element is -1, replace it with the maximum value from its column
                if (ans[j][i] == -1) {
                    ans[j][i] = col[i];
                }
            }
        }

        // Return the modified "ans" matrix
        return ans;
    }
};
