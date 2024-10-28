#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long get(vector<int>& nums, int x) {
        long long ans = 0;
        int n = nums.size();

        long long gcd = (x != 0) ? nums[0] : nums[1];
        long long lcm = gcd;

        for (int i = (x == 0 ? 2 : 1); i < n; ++i) {
            if (i == x) continue;
            int a = nums[i];
            gcd = __gcd(gcd, (long long)a);
            lcm = (lcm * a) / __gcd(lcm, (long long)a);
        }

        return gcd * lcm;
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return (long long)nums[0] * nums[0];

        long long maxi = get(nums, -1);

        for (int i = 0; i < n; ++i) {
            maxi = max(maxi, get(nums, i));
        }

        return maxi;
    }
};
