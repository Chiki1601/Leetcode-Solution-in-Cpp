class Solution {
public:
    inline static pair<int, int> dp[51][51][51][51];
    inline static int vis[51][51][51][51];
    inline static int test_id = 0;
    vector<int> d,f,pref;
    pair<int,int> solve(int i,int d0,int d1,int f0){
        if(i == d.size())return {0,0};
        if (vis[i][d0][d1][f0] == test_id) {
            return dp[i][d0][d1][f0];
        }
        vis[i][d0][d1][f0] = test_id;
        pair<int,int> best = {-1,1e9};
        int u0 = f[0] - f0;
        int u1 = pref[i] - u0;
        int f1 = f[1] - u1;
        if(f0 >= d[i]){
            auto res = solve(i+1,d[i],max(0,d1-d0),f0-d[i]);
            int cars = 1 + res.first;
            int wait = max(d0,res.second);
            if(cars > best.first || (cars == best.first && wait < best.second)){
                best = {cars, wait};
            }
        }
        if(f1 >= d[i]){
            auto res = solve(i+1,max(0,d0-d1),d[i],f0);
            int cars = 1 + res.first;
            int wait = max(d1, res.second);
            if(cars > best.first || (cars == best.first && wait < best.second)){
                best = {cars, wait};
            }
        }
        if(best.first == -1){
            best = {0,0};
        }
        return dp[i][d0][d1][f0]=best;
    }
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        this-> d = demand;
        this-> f = fuel;
        int n = d.size();
        pref.assign(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + d[i];
        }
        test_id++;
        pair<int,int> ans = solve(0,0,0,this->f[0]);
        return ans.first == 0 ? -1 : ans.second;
    }
};
