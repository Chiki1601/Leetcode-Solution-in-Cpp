class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans=0;
        int i=0;
         while(i<nums.size() && s[i]=='1'){
                ans+=nums[i];
             i++;
         }
        for(i;i<nums.size();i++){
            if(s[i]=='1'){
            long long csm=0;
            int mn=INT_MAX;
                csm+=nums[i-1];
                mn=nums[i-1];
                while(i<nums.size() && s[i]=='1'){
                    csm+=nums[i];
                    mn=min(mn,nums[i]);
                    i++;
                }
                ans+=csm-mn;
            }
        }
        return ans;
    }
};
