class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int s=1,sum=0;
        for(auto x:nums) sum +=x*s,s*=-1;
        return sum;
    }
};
