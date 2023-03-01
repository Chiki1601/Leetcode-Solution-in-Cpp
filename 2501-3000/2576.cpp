class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()/2;
        while (r<nums.size() and l<nums.size()/2)
        {
            if(2*nums[l]<=nums[r]) l++;
            r++;
        }
        return l*2;
    }
};
