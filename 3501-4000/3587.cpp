typedef long long ll;
class Solution {
public:
    ll solve(int k ,vector<int> nums) {
        int n = nums.size();
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            int expect = (i % 2 == 0 ? k : 1 - k);
            if (nums[i] % 2 != expect) {
                int j = i + 1;
                while (j < n && nums[j] % 2 != expect) j++;
                if (j == n) return LLONG_MAX;
                while (j > i) {
                    swap(nums[j], nums[j - 1]);
                    j--;
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int minSwaps(vector<int>& nums) {
        ll ans = min(solve(0, nums), solve(1, nums));
        return ans == LLONG_MAX ? -1 : int(ans);
    }
};
