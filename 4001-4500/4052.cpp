class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> temp(n, vector<int>(n, 0));

        // Step 1: Apply cyclic shifts to each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = grid[i][(j + rowShift[i]) % n];
            }
        }

        // Step 2: Apply cyclic shifts to each column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[j][i] = temp[(j + colShift[i]) % n][i];
            }
        }

        return grid;
    }
};
