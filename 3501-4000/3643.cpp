class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x;
        int j = x + k - 1;

        while(i < j) {
            for(int z = y; z < y + k; z++) {
                swap(grid[i][z], grid[j][z]);
            }
            i++;
            j--;
        }
        return grid;
    }
};
