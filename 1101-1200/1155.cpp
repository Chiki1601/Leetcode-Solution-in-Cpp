class Solution {
    vector<unordered_map<int, int>> m;
    long mod = 1e9+7;
    int dfs(int d, int f, int target) {
        if (target < d || target > d * f) return 0;
        if (d == 1) return 1; 
        if (m[d].count(target)) return m[d][target];
        long cnt = 0;
        for (int j = 1; j <= f && j <= target; ++j) {
            int c = dfs(d - 1, f, target - j);
            cnt = (cnt + c) % mod;
        }
        return m[d][target] = cnt;
    }
public:
    int numRollsToTarget(int d, int f, int target) {
        m.assign(d + 1, {});
        return dfs(d, f, target);
    }
};
