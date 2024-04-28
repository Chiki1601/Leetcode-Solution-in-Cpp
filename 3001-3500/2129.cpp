#include <vector>

class Solution {
public:
    int numberOfRightTriangles(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<int> row_counts(rows, 0);
        std::vector<int> col_counts(cols, 0);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    row_counts[r]++;
                    col_counts[c]++;
                }
            }
        }
        int triangles = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    triangles += (row_counts[r] - 1) * (col_counts[c] - 1);
                }
            }
        }
        return triangles;
    }
};
