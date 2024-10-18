class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[3][1001][2001];

    long long solveMem(string &s, int prev, int curr, long long bob) {
        if (curr >= s.size()) {
            return bob > 0 ? 1 : 0;
        }

        if (dp[prev][curr][bob + 1000] != -1) 
            return dp[prev][curr][bob + 1000];

        long long f = 0, w = 0, e = 0;
        if (s[curr] == 'F') {
            if (prev != 0) 
                f = solveMem(s, 0, curr + 1, bob) % MOD % MOD;
            if (prev != 1) 
                w = solveMem(s, 1, curr + 1, bob + 1) % MOD;
            if (prev != 2)
                e = solveMem(s, 2, curr + 1, bob - 1) % MOD;
        } 
        else if (s[curr] == 'W') {
            if (prev != 0) 
                f = solveMem(s, 0, curr + 1, bob - 1)% MOD;
            if (prev != 1) 
                w = solveMem(s, 1, curr + 1, bob) % MOD;
            if (prev != 2) 
                e = solveMem(s, 2, curr + 1, bob + 1) % MOD;
        } 
        else { 
            if (prev != 0) 
                f = solveMem(s, 0, curr + 1, bob + 1) % MOD;
            if (prev != 1) 
                w = solveMem(s, 1, curr + 1, bob - 1)% MOD;
            if (prev != 2) 
                e = solveMem(s, 2, curr + 1, bob) % MOD;
        }
        
        return dp[prev][curr][bob + 1000] = (f + w + e);
    }

    int countWinningSequences(string s) {
        long long ans = 0;
        int n = s.size();
        memset(dp, -1, sizeof(dp));

        ans = (solveMem(s, 0, 0, 0) + solveMem(s, 1, 0, 0) + solveMem(s, 2, 0, 0));
        
        return (ans / 2) % MOD;
    }
};
