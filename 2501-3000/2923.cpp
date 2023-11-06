class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int i=0; i<n; i++){
            bool temp=true;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(grid[i][j]!=1){
                    temp = false;
                }
            }
            if(temp) return i;
        }
        return n-1;
    }
};
