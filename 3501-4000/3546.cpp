class Solution {
public:
    void computeSums(const std::vector<std::vector<int>>& grid, std::vector<long long>& rowSums, std::vector<long long>& colSums, long long& total) {
        int rows = grid.size();
        int cols = grid[0].size();

        int i = 0;
        while (i < rows) {
            int j = 0;
            while (j < cols) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
                total += grid[i][j];
                j++;
            }
            i++;
        }
    }

    bool hasHorizontalCut(const std::vector<long long>& rowSums, long long totalSum) {
        int index = 0;
        long long sumTop = 0;
        while (index < (int)rowSums.size() - 1) {
            sumTop += rowSums[index];
            if (sumTop * 2 == totalSum) return true;
            index++;
        }
        return false;
    }

    bool hasVerticalCut(const std::vector<long long>& colSums, long long totalSum) {
        int idx = 0;
        long long sumLeft = 0;
        while (idx < (int)colSums.size() - 1) {
            sumLeft += colSums[idx];
            if (sumLeft * 2 == totalSum) return true;
            idx++;
        }
        return false;
    }

    bool canPartitionGrid(std::vector<std::vector<int>>& grid) {
        int rowCount = grid.size();
        int colCount = grid[0].size();

        std::vector<long long> rowSums(rowCount, 0);
        std::vector<long long> colSums(colCount, 0);
        long long totalSum = 0;

        computeSums(grid, rowSums, colSums, totalSum);

        return hasHorizontalCut(rowSums, totalSum) || hasVerticalCut(colSums, totalSum);
    }
};
