class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int l=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                sum+=nums[i];
            } 
            mp[nums[i]]++;
             while(k<=sum){
                  mp[nums[l]]--;
                 if(mp[nums[l]]==0){
                     mp.erase(nums[l]);
                     sum-=nums[l];
                 }
                
                 ans=min(ans,i-l+1);
                 l++;
             }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
