class Solution {
    // Directions allowed.
    int dirs[4][2] = {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}
    };

    // Priority queue element: Cell, 
    // indicating 'color' through which we reached cell at '(row, col)' index.
    struct Cell {
        int color;
        int row;
        int col;
    };
    // Custom comparator for priority queue elements.
    struct CompareColor {
        bool operator()(const Cell& p1, const Cell& p2) {
            return p1.color < p2.color; 
        }
    };
    
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        // Cell: { color, row, col } : keep highest color value on top.
        priority_queue<Cell, vector<Cell>, CompareColor> currLevel;

        // Generate colored grid.
        vector<vector<int>> grid (n, vector<int>(m, 0));
 
        // Color all source cells in the grid.
        for (auto& source: sources) {
            grid[source[0]][source[1]] = source[2];
            currLevel.push(Cell(source[2], source[0], source[1]));
        }

        // Iterate on all current level's coloured cells of grid.
        while (!currLevel.empty()) {
            int nodesInCurrLevel = currLevel.size();
            // Store the next level of 'coloured cells' of grid.
            priority_queue<Cell, vector<Cell>, CompareColor> nextLevel;
            
            for (int i = 0; i < nodesInCurrLevel; ++i) {
                auto currCell = currLevel.top();
                currLevel.pop();
                // Iterate on adjacent cells of the current cell.
                for (auto& dir: dirs) {
                    int nextRow = currCell.row + dir[0];
                    int nextCol = currCell.col + dir[1];
                    // If the next level cell lies in the grid, 
                    // and is uncoloured, color it and push it in the queue.
                    if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && grid[nextRow][nextCol] == 0) {
                        grid[nextRow][nextCol] = currCell.color;
                        nextLevel.push(Cell(currCell.color, nextRow, nextCol));
                    }
                }
            }

            // Next level will become current level for next iteration.
            currLevel = nextLevel;
        }

        return grid;
    }
};
