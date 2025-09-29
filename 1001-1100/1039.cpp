class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // dp[i][j] mean we have vi ~ vj
        // key points: everytime use edge(vi,vj) to be choose edge
        //             and then find one node as the remain vertex
        // Therefore, dp[i][j] = min(v[i]*v[j]*v[k] + dp[i][k] + dp[k][j])
        // if j < i + 2, dp[i][j] = 0 => cannot be triangle 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int diff = 2; diff < n; ++diff){
            for(int ind = 0; ind < n-diff; ++ind){
                // calculate dp[ind][ind+diff]
                int s = ind, e = ind+diff;
                dp[s][e] = INT_MAX;
                for(int t = s+1; t < e; ++t){
                    dp[s][e] = min(dp[s][e], dp[s][t] + dp[t][e] + values[s]*values[t]*values[e]);
                }
            }
        }
        return dp[0][n-1];
    }
};
