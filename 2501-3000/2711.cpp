class Solution {
public:
      vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    int row = grid.size();
    int col= grid[0].size();
    
    vector<vector<int>> ans(row, vector<int>(col));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            unordered_set<int> left;
            unordered_set<int> right;
            
            int r = i - 1;
            int c = j - 1;
            while (r >= 0 && c >= 0) {   // checking top left diagonal
                left.insert(grid[r--][c--]);  // inserting in set to count distinct element
            }
            
            r = i + 1;
            c = j + 1;
            while (r < row && c < col) {        // checking bottom right diagonal 
                right.insert(grid[r++][c++]);    // inserting in set to count distinct element
            }
            int topleftdiagonal_distinct=left.size();
            int rightBottomdiagonal_distinct=right.size();
            
            ans[i][j] = abs(topleftdiagonal_distinct-rightBottomdiagonal_distinct);
        }
    }
    
    return ans;
    }
        
    
};
