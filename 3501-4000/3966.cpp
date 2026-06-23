class Solution {
public:
   // idx,prev dig,tight,lz
    long long dp[18][11][2][2];
    long long solve(int idx,int prev,int tight,int lz,string s,int k){
        //B.C
        if(idx>=s.length()){
            return !lz;
        }
        if(dp[idx][prev][tight][lz] != -1){
            return dp[idx][prev][tight][lz];
        }
        int up = s[idx]-'0';
        if(!tight){
            up = 9;
        }
        long long cnt = 0;
        for(int dig=0;dig<=up;dig++){
            int newtight = tight && (dig == up);
            int newlz = lz && (dig == 0);
            if(newlz){
                cnt += solve(idx+1,10,newtight,newlz,s,k);
            } else if(prev == 10 || abs(prev-dig)<=k){
                cnt+=solve(idx+1,dig,newtight,newlz,s,k);
            }
        }
        return dp[idx][prev][tight][lz] = cnt;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string s = to_string(l-1);
        string t = to_string(r);
        memset(dp,-1,sizeof(dp));
        long long left = solve(0,10,1,1,s,k);
        memset(dp,-1,sizeof(dp));
        long long right = solve(0,10,1,1,t,k);
        return right-left;
    }
};
