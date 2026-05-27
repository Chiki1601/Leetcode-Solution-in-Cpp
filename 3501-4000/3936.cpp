class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int ct=0;
        for(int x:nums)if(x==0)ct++;
        int j=nums.size()-1;
        int bc=0;
        int tmp=ct;
        while(tmp--){
            if(nums[j]==0)bc++;
            j--;
        }
        return ct-bc;
    }
};
