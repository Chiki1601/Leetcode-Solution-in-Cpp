class Solution {
    long long dfs(int x, int mask, const string &s, const vector<vector<int>>& con, unordered_map<int, int>& have) {
        long long r = 0;
        if (x) {
            mask ^= 1 << (s[x] - 'a');
            for (int i = 1 << 25; i; i >>= 1) {
                if (have.count(mask ^ i)) {
                    r += have[mask ^ i];
                }
            }
            r += have[mask]++;
        }
        for (int y : con[x]) {
            r += dfs(y, mask, s, con, have);
        }
        return r;
    }
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        const int n = s.length();
        vector<vector<int>> con(n);
        for (int i = 1; i < n; ++i) {
            con[parent[i]].push_back(i);
        }
        unordered_map<int, int> have;
        have[0] = 1;
        return dfs(0, 0, s, con, have);
        
    }
};
