class Solution {
public:
    vector<string> createGrid(int rows, int cols) {

        // Initially fill the entire grid with blocked cells ('#')
        string blockedRow(cols, '#');
        vector<string> grid(rows, blockedRow);

        // Open all cells in the first row
        for (int col = 0; col < cols; col++) {
            grid[0][col] = '.';
        }

        // Open all cells in the last column
        for (int row = 1; row < rows; row++) {
            grid[row][cols - 1] = '.';
        }

        return grid;
    }
};
