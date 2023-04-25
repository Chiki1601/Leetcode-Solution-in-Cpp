class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), 1);
        for(auto i = 0; i < grid[0].size(); ++i){
            for(auto j = 0; j < grid.size(); ++j){
                int t = to_string(grid[j][i]).size(); 
                ans[i] = max(ans[i], t);
            }
        }
        return ans;
    }
};
