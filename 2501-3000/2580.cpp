class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int res = 1, last = -1, mod = 1e9 + 7;
        sort(ranges.begin(), ranges.end());
        for (auto r: ranges) {   
            if (last < r[0])
                res = res * 2 % mod;
            last = max(last, r[1]);
        }
        return res;
    }
};
