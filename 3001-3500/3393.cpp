class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        unordered_map<long long, int> memo; 

        function<int(int, int, int)> dfs = [&](int row, int col, int current_xor) {
            if (row == m - 1 && col == n - 1) {
                return ((current_xor ^ grid[row][col]) == k) ? 1 : 0;
            }

            long long key = ((long long)row << 32) | ((long long)col << 16) | current_xor;
            if (memo.count(key)) {
                return memo[key];
            }

            int paths = 0;
            if (row + 1 < m) {
                paths = (paths + dfs(row + 1, col, current_xor ^ grid[row][col])) % MOD;
            }
            if (col + 1 < n) {
                paths = (paths + dfs(row, col + 1, current_xor ^ grid[row][col])) % MOD;
            }

            memo[key] = paths;
            return paths;
        };

        return dfs(0, 0, 0);
    }
};
