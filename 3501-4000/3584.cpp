typedef long long ll;
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        ll ans = LLONG_MIN;

        // If m == 1, return the maximum square of any number
        if (m == 1) {
            for (auto it : nums) {
                ll v = (ll)it * it;
                ans = max(ans, v);
            }
            return ans;
        }

        // Initialize max and min of first elements in window
        ll maxi = LLONG_MIN;
        ll mini = LLONG_MAX;

        // Sliding window of size m
        for (int j = m - 1; j < n; j++) {
            int i = j - m + 1; // start of the window
            maxi = max(maxi, (ll)nums[i]);
            mini = min(mini, (ll)nums[i]);

            ll prod1 = maxi * nums[j];
            ll prod2 = mini * nums[j];
            ans = max(ans, max(prod1, prod2));
        }

        return ans;
    }
};
