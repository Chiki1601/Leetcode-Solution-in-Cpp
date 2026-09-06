class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<vector<int>>>> dist(m, 
    vector<vector<vector<int>>>(n, 
        vector<vector<int>>(k + 1, 
            vector<int>(5, 1e9))));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,grid[0][0],1,0,0});
        pq.push({0,grid[0][0],2,0,0});
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        dist[0][0][0][1]=grid[0][0];
        dist[0][0][0][2]=grid[0][0];
        while(!pq.empty()){
            int turns=pq.top()[0];
            int cost=pq.top()[1];
            int dir=pq.top()[2];
            int i=pq.top()[3];
            int j=pq.top()[4];
            
            pq.pop();
            if(dist[i][j][turns][dir]<cost)
            continue;
            for(int y=0;y<4;y++){
                int nr=i+dx[y];
                int nc=j+dy[y];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int nturns=turns;
                    if(y!=dir){
                        nturns=turns+1;
                    }
                    if(nturns<=k){
                    if(dist[nr][nc][nturns][y]>cost+grid[nr][nc]){
                        dist[nr][nc][nturns][y]=cost+grid[nr][nc];
                        pq.push({nturns,dist[nr][nc][nturns][y],y,nr,nc});
                    }
                    }
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=4;j++)
            ans=min(ans,dist[m-1][n-1][i][j]);
        }
        return ans==1e9?-1:ans;
    }
};
