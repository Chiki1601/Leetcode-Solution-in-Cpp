class Solution {
public:
    const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        for (auto &it : q) {
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            while (l <= r) {
                nums[l] = (1LL * nums[l] * v) % mod;
                l += k;
            }
        }
        int ans = 0;
        for (auto &it : nums) {
            ans ^= it;
        }
        return ans;
    }
};
