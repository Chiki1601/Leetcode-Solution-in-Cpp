class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int yk=nums[nums.size()-1]*k;
        // int op=k;
        k--;
       int yk2=k*(k+1);
        yk2/=2;
        // yk*=op;
        yk+=yk2;
        return yk;
    }
};
