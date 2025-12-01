class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (k == 0) return nums.size();

        sort(nums.begin(), nums.end());
        int n = nums.size();

        // k-th largest element is at index n-k
        int threshold = nums[n - k];

        int ans = 0;
        for (int x : nums) {
            if (x < threshold) {
                ans++;
            }
        }

        return ans;
    }
};
