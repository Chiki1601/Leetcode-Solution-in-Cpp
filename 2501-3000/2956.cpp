class Solution {
public:
   vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    vector<int> freq1(101, 0), freq2(101,0);
    int res1 = 0, res2 = 0;
    for(auto n: nums1) freq1[n]++;
    for(auto n: nums2) freq2[n]++;
    for(int i = 1; i <= 100; ++i) {
        if(freq2[i]) res1 += freq1[i];
        if(freq1[i]) res2 += freq2[i]; 
    }
    return {res1, res2};
}
};
