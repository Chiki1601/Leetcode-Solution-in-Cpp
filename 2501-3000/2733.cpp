class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3)
            return -1;

        int a = min(nums[0],nums[1]);
        int b = max(nums[0],nums[1]);
        int c = nums[2];

        if(c<b && c>a) return c; // since c cannot be the maximum nor the minimum now
        if(c<a) return a; //since a cannot be the minimum as it is bigger than one number and smaller than b
        if(c>b) return b; //since b cannot be minimum as it is bigger than a and cannot be max as it is < b

        return -1;
    }
};
