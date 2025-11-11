class Solution {
public:
    int minMoves(vector<int>& nums) {
        int MAX = nums[0], ans = 0;
        for(int i = 1; i < nums.size(); i++) MAX = max(MAX, nums[i]);
        for(int i = 0; i < nums.size(); i++) ans += MAX - nums[i];
        return ans;
    }
};
