class Solution {
public:
   int cache[1001][51] = {};
int waysToReachTarget(int target, vector<vector<int>>& types) {
    memset(cache, -1, sizeof(cache)); // initialize cache with -1
    function<int(int, int)> dfs = [&](int i, int target) {
        if (target == 0) return 1;
        if (i >= types.size() || target < 0) return 0;
        if (cache[target][i] != -1) return cache[target][i];
        int ans = 0;
        for (int j = 0; j <= types[i][0]; j++)
            ans = (ans + dfs(i + 1, target - j * types[i][1])) % 1000000007;
        return cache[target][i] = ans;
    };
    return dfs(0, target);
}
};
