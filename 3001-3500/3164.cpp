class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    long long ans = 0;
    unordered_map<int,int> freq;
    for(auto n: nums2) freq[n*k]++;
    for(auto n: nums1){
        int sr = sqrt(n);
        for(int i = 1; i <= sr; ++i){
            if(n%i != 0) continue;
            ans += freq[i];
            if(i != n/i) ans += freq[n/i];
        }
    }
    return ans;
}
};
