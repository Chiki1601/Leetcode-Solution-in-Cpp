class Solution {
public:
    vector<vector<int>>dp; // craete DP
    int memo(int i, int x,string &s1, string &s2, int xInUse){
        if(i >= s1.size()) return 0; // base case
        if(dp[i][xInUse] != -1) return dp[i][xInUse];
        if(s1[i] != s2[i]){ 
            s1[i] = (1 - (s1[i] - '0')) + '0'; // flip S1[i]
            s1[i+1] = (1 - (s1[i+1] - '0')) + '0'; // flip S1[i+1]
            int pick = 1 + memo(i+1,x,s1,s2,xInUse);
            s1[i] = (1 - (s1[i] - '0')) + '0'; // undo flip
            s1[i+1] = (1 - (s1[i+1] - '0')) + '0'; // undo flip
            int nonPick = INT_MAX;
            if(xInUse){
                // if x in use, no need to wase x money
                nonPick = memo(i+1,x,s1,s2,0); 
            }else{
                // if x not in use, use x amount
                nonPick = x+memo(i+1,x,s1,s2,1);
            }
            // cout<<pick<<" "<<nonPick<<"\n";
            return dp[i][xInUse] = min(pick,nonPick); //return minimum
        }
        //directly move ahead since s1[i] == s2[i]
        return dp[i][xInUse] = memo(i+1,x,s1,s2,xInUse);
        
    }
    int minOperations(string s1, string s2, int x) {
        int cnt = 0;
        dp.resize(s1.size()+1,vector<int>(2,-1));
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i]) cnt++;
        }
        if(cnt% 2 == 1) return -1;
        return memo(0,x,s1,s2,0);
    }
};
