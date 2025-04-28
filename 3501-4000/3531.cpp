class Solution {
public:
    int count = 0;
    int countCoveredBuildings(int n, vector<vector<int>>& grid) {
        for (int i = 0 ; i < grid.size() ; i++) 
            if (isBuilding(grid, grid[i][0], grid[i][1])) ++count;
        
        return count;
    }
    
    bool isBuilding(vector<vector<int>>& grid, int x, int y) {
        bool up = 0, down = 0, left = 0, right = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == x && grid[i][1] == y) continue;
            if (grid[i][0] == x && grid[i][1] < y) up = true;
            if (grid[i][0] == x && grid[i][1] > y) down = true;
            if (grid[i][1] == y && grid[i][0] < x) left = true;
            if (grid[i][1] == y && grid[i][0] > x) right = true;
        }
        return up && down && left && right;
    }
};
