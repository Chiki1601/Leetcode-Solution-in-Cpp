class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        int c=1;
        vector<int> ans;

        for(int i=1;i<=n;i++){
            if(i<n and nums[i-1]==nums[i]) c++;
            else{
                int len = min(c,k);
                while(len--) ans.push_back(nums[i-1]);
                c=1;
            }
        }
        return ans;
    }
};
