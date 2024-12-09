class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end()); 
        if (mn < k) {
            return -1; 
        }
        unordered_map<int,int> mp; 
        for (auto &it: nums) {
            mp[it] = 1; 
        }
        int ans = mp.size(); 
        if (mp[k]) {
            ans--; 
        }
        return ans; 
    }
};
