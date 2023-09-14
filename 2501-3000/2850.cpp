class Solution {
    
public:
    vector<vector<int>> ref = {{1,1,1},{1,1,1},{1,1,1}};
    int help(vector<vector<int>>& grid)
    {
        if(grid==ref)
            return 0;
        int ans = 30;
        for(int i = 0;i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                for(int k = 0 ; k<3;k++)
                {
                    for(int l = 0;l<3;l++)
                    {
                        if(grid[i][j]==0 && grid[k][l]>1)
                        {
                            grid[i][j]++;
                            grid[k][l]--;
                            ans = min(ans,abs(i-k)+abs(j-l)+help(grid));
                            grid[i][j]--;
                            grid[k][l]++;
                        }
                    }
                }
            }
        }
        return ans; 
    }
    int minimumMoves(vector<vector<int>>& grid) {
        return help(grid);
    }
};
