class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int a=INT_MAX;
        for(auto it:nums)a&=it;
        if(a!=0)return 1;
        int b=INT_MAX;
        int count=0;
        for(auto it:nums){
            b&=it;
            if(b==0){
                count++;
                b=INT_MAX;
            }
        }
        return count;
    }
};
