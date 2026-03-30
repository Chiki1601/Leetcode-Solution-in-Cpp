class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int l=-1,r=-1,ans=1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) l=i;
            else if(nums[i]==2) r=i;

            if(l!=-1 and r!=-1) ans = min(ans,abs(l-r));
        }
        return ans==1e9?-1:ans;
    }
};
