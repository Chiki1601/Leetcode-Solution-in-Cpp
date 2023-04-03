class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq(10);
        for(int i=0; i<nums1.size(); i++) freq[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) freq[nums2[i]]++;
            
        int k=2;
        int ans =0;
        int mn1 = *min_element(nums1.begin(), nums1.end());
        int mn2 = *min_element(nums2.begin(), nums2.end());
        for(int i=1; i<=9; i++)
            if(freq[i]==2) return i;
        
        if(mn2<mn1) swap(mn2, mn1);
        return mn1*10+mn2;
    }
};
