class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int start = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            // here nums[i] = maxi and nums[start] = mini
            // while window is not vaild increase the current minimum 
            while(nums[i]-nums[start] > 2*k)
                start++;
            // the current window i.e. [start ... i] is valid so consider it
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};
