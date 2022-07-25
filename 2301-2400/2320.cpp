const int mod = 1e9 + 7;
class Solution {
    
public:
    int countHousePlacements(int n) {
    
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        
        f[1][0] = f[1][1] = 1;
        for(int i = 2 ; i <= n; i ++)
        {
    
            f[i][1] = f[i - 1][0] % mod;
            f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
        }
        long long t = 0LL + f[n][1] + f[n][0];
        return t * t % mod;
    }
};
