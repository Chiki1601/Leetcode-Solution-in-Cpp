int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int ans = 0;
    for(int i = 0; i < nums1.size(); ++i){
        for(int j = 0; j < nums2.size(); ++j){
            int div = nums2[j]*k;
            if(nums1[i]%div == 0) ans++;
        }
    }
    return ans;
}
