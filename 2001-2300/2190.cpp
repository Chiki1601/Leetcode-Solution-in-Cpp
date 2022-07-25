class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> mp;
        for (int i = 0; i + 1 < nums.size(); i++) if (nums[i] == key) mp[nums[i + 1]]++;
        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) if (ans == 0 || mp[ans] < it->second) ans = it->first;
        return ans;
    }
};

