class Solution {
public:
    int dp[1001] = {};
    int solve(vector<int>& prices, int i){
        if(i >= prices.size()) return 0;
        if(dp[i]) return dp[i];
        int res = INT_MAX;
        for(int j = i+1; j <= 2*i + 2; ++j){
            res = min(res, solve(prices, j));
        }
        return dp[i] = res + prices[i];
    }

    int minimumCoins(vector<int>& prices) {
        return solve(prices, 0);
    }
};
