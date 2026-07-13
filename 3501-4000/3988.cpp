class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        swap(m, n);

        vector<string> grid(n, string(m, '#'));

        // Single row or single column
        if (n == 1 || m == 1) {
            if (k != 1)
                return {};

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = '.';
                }
            }
            return grid;
        }

        // Two rows or two columns
        if (n == 2 || m == 2) {
            int len = max(n, m);

            if (k > len)
                return {};

            if (n == 2) {
                // Open the entire first row
                for (int j = 0; j < m; j++)
                    grid[0][j] = '.';

                // Open last k cells of second row
                for (int j = m - 1; j >= m - k; j--)
                    grid[1][j] = '.';
            } else {
                // Open the entire first column
                for (int i = 0; i < n; i++)
                    grid[i][0] = '.';

                // Open last k cells of second column
                for (int i = n - 1; i >= n - k; i--)
                    grid[i][1] = '.';
            }

            return grid;
        }

        int startRow = n - 3;
        int startCol = m - 3;

        vector<string> pattern(3);

        switch (k) {
            case 1:
                pattern = {
                    "...",
                    "##.",
                    "##."
                };
                break;

            case 2:
                pattern = {
                    "...",
                    "#..",
                    "##."
                };
                break;

            case 3:
                pattern = {
                    "...",
                    "#..",
                    "#.."
                };
                break;

            case 4:
                pattern = {
                    "..#",
                    "...",
                    "#.."
                };
                break;
        }

        // Create the path
        for (int i = 0; i <= startRow; i++)
            grid[i][startCol] = '.';

        for (int j = 0; j <= startCol; j++)
            grid[0][j] = '.';

        // Copy the 3×3 pattern
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[startRow + i][startCol + j] = pattern[i][j];
            }
        }

        return grid;
    }
};
