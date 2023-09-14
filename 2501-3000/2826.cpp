class Solution {
public:

	int dp[102][4];

	int solve(vector<int>& nums, int ind, int prev) {
		if (ind == nums.size()) return 0;

		int ans = 500;
		if (dp[ind][prev] != -1) return dp[ind][prev];

		if (nums[ind] >= prev) {
			// already in non-decreasing order
			// two options

            // option 1
			int temp = solve(nums, ind + 1, nums[ind]);
			ans = min(temp, ans);

            // option 2
			for (int i = prev; i <= 3; i++) {
				int temp = solve(nums, ind + 1, i);
				ans = min(1 + temp, ans);
			}

		} else {
			// only option is to change the nums[index] such that nums[ind] >= prev
			for (int i = prev; i <= 3; i++) {
				int temp = solve(nums, ind + 1, i);
				ans = min(1 + temp, ans);
			}
		}
		return dp[ind][prev] = ans;
	}

	int minimumOperations(vector<int>& nums) {
		memset(dp, -1, sizeof(dp));
		return solve(nums, 0, 0);
	}
};
