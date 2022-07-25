const int N = 1e4 + 10, mod = 1e9 + 7;
class Solution {
public:
    int f[N][10][10];
    bool can[10][10];
    int distinctSequences(int n) {
        if(n == 1) return 6;
        for(int i = 1; i <= 6; i ++ )
            for(int j = 1; j <= 6; j ++ )
                if(__gcd(i, j) == 1 && i != j) can[i][j] = true, f[2][i][j] = 1;
                else can[i][j] = false;
        for(int i = 3; i <= n; i ++ ){
            for(int j = 1; j <= 6; j ++ ){
                for(int k = 1; k <= 6; k ++ ){
                    for(int z = 1; z <= 6; z ++ ){
                        if(!can[k][z] || !can[j][k]) continue;
                        if(j == z || j == k || k == z) continue;
                        f[i][j][k] = (f[i][j][k] + f[i - 1][k][z]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= 6; i ++ )
            for(int j = 1; j <= 6; j ++ ){
                if(can[i][j]) ans = (ans + f[n][i][j]) % mod;
            }
        return ans;
    }
};

