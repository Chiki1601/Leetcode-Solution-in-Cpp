class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        unordered_map<int, int> dp;
        int max_length = 1;

        for (int num : nums) {
            if (dp.find(num - difference) != dp.end()) {
                dp[num] = dp[num - difference] + 1;
            } else {
                dp[num] = 1;
            }

            max_length = max(max_length, dp[num]);
        }

        return max_length;
    }
};
