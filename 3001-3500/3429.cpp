class Solution {
    long long f(int i, int left, int right, int n, vector<vector<int>>& cost, vector<vector<vector<long long>>>& dp) {
        
        if(i >= n/2) return 0;
        if(dp[i][left][right]!=-1) return dp[i][left][right];

        long long t = LONG_MAX;
        for(int col1=0; col1<3; col1++) {
            if(col1 != left) {
                for(int col2=0; col2<3; col2++){
                    if((col2 != right) && (col2 != col1)) {
                        long long q = cost[i][col1] + cost[n-1-i][col2] + f(i+1, col1, col2, n, cost, dp);
                        t = min(t, q);
                    }
                }
            }
        }
        return dp[i][left][right] = t;
    }
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(4, vector<long long>(4, -1)));
        return f(0, 3, 3, n, cost, dp);
    }
};
