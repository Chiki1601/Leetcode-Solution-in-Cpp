class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int i=0, ans= 1, n = nums.size();
        while(i<n){
            if(nums[i] == mx){
                int count = 0, j = i;
                while(j<n &&  nums[j]==mx) count++, j++;
                i = j;
                ans = max(ans,count);
            }
            else i++;
        }
        return ans;
    }
};
