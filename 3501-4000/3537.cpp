class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;
        vector<vector<int>> grid(size, vector<int>(size));
        solve(grid, 0, size, 0, size);
        return grid;
    }
private:
    int val = 0;
    void solve(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd){
        int size = rowEnd - rowStart;
        if (size == 1){
            grid[rowStart][colStart] = val++;
            return;
        }
        int midRow = rowStart + size / 2;
        int midCol = colStart + size / 2;

        solve(grid, rowStart, midRow, midCol, colEnd); // top right
        solve(grid, midRow, rowEnd, midCol, colEnd); // bottom right
        solve(grid, midRow, rowEnd, colStart, midCol); // bottom left
        solve(grid, rowStart, midRow, colStart, midCol); // top left
    }
};
