class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        
        vector<vector<int>> h=g;
        vector<vector<long long >> grid(g.size(),vector<long long >(g[0].size(),0));
        
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                long long p=(long long) g[i][j];
                grid[i][j]=p;
            }
        }
        
        
        for(int i=0;i<grid.size();i++){
            for(int j=1;j<grid[i].size();j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        
        for(int j=0;j<grid[0].size();j++){
            for(int i=1;i<grid.size();i++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        
        // cout<<grid[2][2];
        long long ans=INT_MIN;
        for(int i=2;i<grid.size();i++){
            for(int j=2;j<grid[i].size();j++){
                long long l=0,u=0;
                bool flg1=0,flg2=0;
                long long res=grid[i][j];
                
                if(i-2-1>=0){
                    u=grid[i-2-1][j];
                    flg1=1;
                    res-=u;
                }
                if(j-2-1>=0){
                    l=grid[i][j-2-1];
                    flg2=1;
                    res-=l;
                }
                
                if(flg2 && flg1){
                    res+=grid[i-2-1][j-2-1];
                }
                // cout<<res<<" "<<grid[i-1][j-2]<<" "<<grid[i-1][j]<<" r";
                res-=(long long )h[i-1][j-2];
                res-=(long long )h[i-1][j];
                // cout<<res<<" ";
                ans=max(ans,res);
                
            }
        }
        
        return ans;
        
        
    }
};
