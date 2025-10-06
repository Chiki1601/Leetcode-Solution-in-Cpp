class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorSum = 0;
        bool allZero = true;
        for (int num : nums) {
            xorSum ^= num;
            if (num != 0) allZero = false;
        }
        if (allZero) return 0;
        return xorSum != 0 ? nums.size() : nums.size() - 1;
    }
};
