class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minArr(n, INT_MAX);
        minArr[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minArr[i] = min(nums[i], minArr[i + 1]);
        }
        int i = 0;
        int maxi = nums[0];
        int mini = minArr[0];
        while (i < n) {
            maxi = max(maxi, nums[i]);
            mini = minArr[i];
            if (maxi - mini <= k)
                return i;

            i++;
        }
        return -1;
    }
};
