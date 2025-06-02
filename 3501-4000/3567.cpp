class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int rows=m-k+1;
        int cols=n-k+1;
        vector<vector<int>>ans(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vector<int>vals(k*k);
                int ind=0;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        vals[ind++]=grid[x][y];
                    }
                }
                sort(vals.begin(),vals.end());
                vector<int>uniq;
                uniq.reserve(k*k);
                uniq.push_back(vals[0]);
                for(int t=1;t<vals.size();t++){
                    if(vals[t]!=vals[t-1]){
                        uniq.push_back(vals[t]);
                    }
                }
                if(uniq.size()<=1){
                    ans[i][j]=0; 
                    continue;
                }
                int mini=INT_MAX;
                for(int t=1;t<uniq.size();t++){
                    int dif=uniq[t]-uniq[t-1];
                    if(dif<mini){
                        mini=dif;
                    }
                    if(mini==0) break;
                }
                ans[i][j]=mini;
            }
        }
        return ans;
    }
};
