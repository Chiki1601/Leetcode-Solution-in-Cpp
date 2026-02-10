class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        
        int res = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            int count = i;
            int num = nums[n - 1 - i]; // reversed(nums)[i]
            if (num * count > sum) 
                res += 1;
            sum += num;
        }
        return res;
    }
};
