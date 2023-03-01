class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int>ans,a;
        a.push_back(0);
        for(int i=0;i<nums.size();i++) a.push_back(a.back()+nums[i]);
        for(int i=1;i<a.size();i++) ans.push_back(abs(a[nums.size()]-a[i]-a[i-1]));
        return ans;
    }
};
