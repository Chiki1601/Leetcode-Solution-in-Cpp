class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int i;
        
        // Step 1: Find the first index where nums and target differ
        for (i = 0; i < n; i++) {
            if (nums[i] != target[i]) break;
        }
        
        // Step 2: Sort the required suffix in descending order
        sort(nums.begin() + i, nums.end(), greater<int>());
        
        // Step 3: Check if sorting the suffix made nums equal to target
        if (nums == target) {
            int ans = 1;
            
            // Step 4: Count how far left we can extend the suffix
            for (int j = min(i - 1, n - 2); j >= 0; j--) {
                if (nums[j] >= nums[j + 1]) {
                    ans++;
                } else {
                    break;
                }
            }
            return ans;
        }
        
        return 0;
    }
};
