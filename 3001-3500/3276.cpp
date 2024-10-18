class Solution {
public:
    int dp[2001][101];
    int solve(int i,int n,vector<int>&t,map<int,vector<int>>&mp,int mask) {
        if(i==n)
            return 0;
        if(dp[mask][i]!=-1)
            return dp[mask][i];
        int ans=0;
        for(auto j:mp[t[i]]) {
            if((mask&(1<<j))==0) {
                ans=max(ans,t[i]+solve(i+1,n,t,mp,(mask|(1<<j))));
            }
        }
        ans=max(ans,solve(i+1,n,t,mp,mask));
        return dp[mask][i]=ans;
    }
    int maxScore(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        set<int>s;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                s.insert(v[i][j]);
            }
        }
        vector<int>t;
        for(auto i:s)
            t.push_back(i);
        sort(t.begin(),t.begin(),greater<int>());
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                mp[v[i][j]].push_back(i);
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,t.size(),t,mp,0);
    }
};
