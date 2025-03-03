class Solution {
public:
    std::vector<int> transformArray(std::vector<int>& nums) {
        // Transform the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;         
            } else {
                nums[i] = 1;
            }
        }
        // Sort the transformed array
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};
