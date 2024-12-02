class Solution {
public:
   int getLargestOutlier(vector<int>& nums) {
    int ans = INT_MIN, sum = 0;
    unordered_map<int, int> freq;
    for(auto n : nums){
        sum += n;
        freq[n*2]++;
    }
    for(auto n: nums){
        int t = sum - n;
        if(freq[t] >= 2 || (freq[t] == 1) && (t != n*2)) ans = max(ans, n);
    }
    return ans;
}
};
