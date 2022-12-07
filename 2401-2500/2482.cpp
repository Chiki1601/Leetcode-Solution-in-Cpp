class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        //make vector for every value
        vector<int> OR(n), ZR(n);           //OnesRow, ZeroRow
        vector<int> OC(m), ZC(m);            //OnesCol, ZeroesCol
            
        //count- for rows
        for(int i=0; i<n; i++){
            int orr=0, zrr=0;               //ones in a row & zeroes in a row
            for(int j=0; j<m; j++){
                if(grid[i][j]==0) zrr++;
                if(grid[i][j]==1) orr++;
            }
            
            // cout<<orr<<" "<<zrr<<endl;
            OR[i] = orr;
            ZR[i] = zrr;
             // cout<<i<<" "<<occ<<" "<<zcc<<endl;
        }
        
        //count- for colm
        for(int i=0; i<m; i++){
            int occ=0, zcc=0;               //ones in a row & zeroes in a row
            for(int j=0; j<n; j++){
                if(grid[j][i]==0) zcc++;
                if(grid[j][i]==1) occ++;
            }
            
            OC[i] = occ;
            ZC[i] = zcc;
            // cout<<OR[i]<<" "<<ZR[i]<<endl;
        }
        
        //business
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = OR[i] + OC[j] - ZR[i] - ZC[j];
                // cout<<OR[i]<<" "<<OC[j]<<" "<<ZR[i]<<" "<<ZC[j]<<endl;
            }
        }
        
        
        // for(int i=0; i<n; i++){
        //     cout<<OR[i]<<" "<<ZR[i]<<endl;
        // }
        
        return ans;
    }
};
