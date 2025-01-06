class Solution {
public:
  long long maximumCoins(vector<vector<int>>& coins, int k) {
    long long res = 0, sum = 0;
    sort(begin(coins), end(coins));
    for (int i = 0, j = 0; i < coins.size(); ++i) {
        long long l = coins[i][0], r = coins[i][1], c = coins[i][2];
        sum += (r - l + 1) * c;
        while(r - k + 1 > coins[j][1]) {
            if (coins[j][0] + k - 1 >= l)
                res = max(res, sum - (r - (coins[j][0] + k - 1)) * c);
            sum -= ((long long)coins[j][1] - coins[j][0] + 1) * coins[j][2];
            ++j;
        }
        if (coins[j][0] + k - 1 >= r)
            res = max(res, sum);
        else {
            res = max(res, sum - (r - k + 1 - coins[j][0]) * coins[j][2]);
            if (coins[j][0] + k - 1 >= l)
                res = max(res, sum - (r - (coins[j][0] + k - 1)) * c);
        }
    }
    return res;
}
};
