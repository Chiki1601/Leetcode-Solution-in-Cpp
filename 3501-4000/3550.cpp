class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (to_string(nums[i]).length() < 2) {
                if (nums[i] == i)
                    return i;
            }
            int sum = 0;
            int num = nums[i];
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            if (sum == i)
                return i;
        }
        return -1;
    }
};
