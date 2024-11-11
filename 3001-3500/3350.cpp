class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
         int flag=0;
        int prev=0;
        int curr=1;
        int ans=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                curr++;
            }
            else{
                prev=curr;
                curr=1;
            }
            ans=max(ans,max(curr/2,min(prev,curr)));
        }
        return ans;
    }
};
