class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<int> v;
        for(int i = 0; i < nums1.size(); i++) {
            if(nums2.size() % 2 == 1) v.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(nums1.size() % 2 == 1) v.push_back(nums2[i]);
        }
        for(int ele : v) ans ^= ele;
        return ans;
    }
};
