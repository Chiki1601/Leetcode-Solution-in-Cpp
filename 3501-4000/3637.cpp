class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // Step 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) ++i;
        if (i == 0 || i == n - 1) return false;

        // Step 2: strictly decreasing
        int p = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) ++i;
        if (i == p || i == n - 1) return false;

        // Step 3: strictly increasing again
        while (i + 1 < n && nums[i] < nums[i + 1]) ++i;

        return i == n - 1;
    }
};
