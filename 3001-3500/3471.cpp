class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    int ans = -1;
    unordered_map<int, int> mp;
    for(int i = 0; i+k <= nums.size(); ++i){
        unordered_set<int> s;
        for(int j = i; j < i+k; ++j){
            if(s.find(nums[j]) == s.end()) mp[nums[j]]++;
            s.insert(nums[j]);
        }
    }
    for(auto [k,v] : mp) ans = max(ans, (v == 1)?k:-1);
    return ans;
}    
};
