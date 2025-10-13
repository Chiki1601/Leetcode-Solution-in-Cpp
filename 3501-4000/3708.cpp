class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int ans = 2, c = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i-1] + nums[i-2]) c++;
            else c = 2;
            ans = max(ans, c);
        }
        return ans;
    }
};
