class Solution {
public:
    int maxArea(vector<vector<int>>& a){
        int n=a.size(),m=a[0].size(),z=min(n,m);
        vector<vector<int>>pf(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pf[i+1][j+1]=pf[i][j+1]+pf[i+1][j]-pf[i][j]+a[i][j];
            }
        }
        auto sum=[&](int r1,int c1,int r2,int c2){
            return pf[r2+1][c2+1]-pf[r1][c2+1]-pf[r2+1][c1]+pf[r1][c1];
        };
        vector<vector<pair<int,int>>>v(z+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=1;i+k<=n&&j+k<=m;k++){
                    if(sum(i,j,i+k-1,j+k-1)==k*k){
                        v[k].push_back({i,j}); // store valid square
                    }else break;
                }
            }
        }
        for(int k=z;k>=1;k--){
            if(v[k].size()<2)continue;
            int x1=n,x2=-1,y1=m,y2=-1;
            for(auto [x,y]:v[k]){
                x1=min(x1,x);
                x2=max(x2,x);
                y1=min(y1,y);
                y2=max(y2,y);
            }
            if(x2-x1>=k||y2-y1>=k)return k*k; // squares do not overlap
        }
        return 0;
    }
};
