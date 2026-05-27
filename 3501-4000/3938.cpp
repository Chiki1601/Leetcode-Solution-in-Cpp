class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            vector<int>pfx(n+1,0);
            for(int j=0;j<n;j++)pfx[j+1]=pfx[j]+grid[i][j];
            for(int j=0;j<n;j++){
                for(int k=j;k<n;k++){
                    int sum=pfx[k+1]-pfx[j];
                    int len=k-j+1;
                    if(len>=2)ans=max(ans,sum);
                    else if(len==1){
                        if(i>0 && i<m-1 && j>0 && j<n-1)ans=max(ans,sum);
                    }
                }
            }
        }

      for(int j=0;j<n;j++){
        vector<int>pfx(m+1,0);
        for(int i=0;i<m;i++)pfx[i+1]=pfx[i]+grid[i][j];
          for(int i=0;i<m;i++){
              for(int k=i;k<m;k++){
                  int sum=pfx[k+1]-pfx[i];
                  int len=k-i+1;
                      if(len>=2)ans=max(ans,sum);
                  else if(len==1){
                      if(i>0 && i<m-1 && j>0 && j<n-1)ans=max(ans,sum);
                  } 
              }
          }
       }
       return ans;
    }
};
