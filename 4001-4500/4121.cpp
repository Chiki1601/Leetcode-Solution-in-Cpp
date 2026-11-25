class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        bool allEqual = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[0]) {
                allEqual = false;
                break;
            }
        }
        if (allEqual) {
            return 0;
        }

        long long ans = LLONG_MAX;
        int l = 0;
        while (l < n) {
            int r = l;
            while (r + 1 < n && nums[r + 1] == nums[l]) {
                r++;
            }
            if (r >= 1 && l <= n - 2) {
                long long runLen = static_cast<long long>(r) - l + 1;
                long long cost = (static_cast<long long>(n) - runLen) * static_cast<long long>(nums[l]);
                ans = min(ans, cost);
            }
            l = r + 1;
        }
        return ans;
    }
};
