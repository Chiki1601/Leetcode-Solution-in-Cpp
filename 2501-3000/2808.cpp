class Solution {
public:
   int minimumSeconds(vector<int>& nums) {
    int ans = INT_MAX, n = nums.size();
    unordered_map<int, int> lastSeen, maxDiff;
    for(int i = 0; i < n; ++i){
        if(lastSeen.find(nums[i]) != lastSeen.end()){
            maxDiff[nums[i]] = max(maxDiff[nums[i]], i - lastSeen[nums[i]] - 1);
        }
        lastSeen[nums[i]] = i;
    }
    for(int i = 0; i < n; ++i){ //to handle rotation repeat the same once again
        maxDiff[nums[i]] = max(maxDiff[nums[i]], (i - lastSeen[nums[i]] -1 + n )%n );
        lastSeen[nums[i]] = i;
    }
    
    for(auto [k, v]: maxDiff) ans = min(ans, v);
    return (ans + 1)/2; 
}
};
