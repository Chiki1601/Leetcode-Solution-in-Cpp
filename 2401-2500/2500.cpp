class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            sort(grid[i].rbegin(), grid[i].rend());
        }
        
        int ans = 0;
        for(int i=0; i<grid[0].size(); i++){
            int val = grid[0][i];
            // cout<<val<<" ";
            for(int j=1; j<grid.size(); j++){
               // cout<<grid[j][i]<<" ";
                val = max(val, grid[j][i]);
            }
            // cout<<endl;
            ans += val;
        }
        return ans;
    }
};
