class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int n = nums.size();
        int max_diff = 0;
        
        for(int i = 0; i < n; ++i) {
            int diff = abs(nums[i] - nums[(i + 1) % n]);
            max_diff = max(max_diff, diff);
        }

        return max_diff;
    }
};
