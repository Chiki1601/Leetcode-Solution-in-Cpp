class Solution {
public:
    const int MOD = 1e9 + 7;
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    int countCoprime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, int> prev;
        for (int j = 0; j < n; j++) {
            prev[mat[0][j]]++;
        }
        for (int i = 1; i < m; i++) {
            map<int, int> cur;
            for (int j = 0; j < n; j++) {
                for (auto [p, f] : prev) {
                    int ind = gcd(mat[i][j], p);
                    cur[ind] = (cur[ind] % MOD + f % MOD) % MOD;
                }
            }
            prev = move(cur);
        }
        return prev[1]%MOD;
    }
};
