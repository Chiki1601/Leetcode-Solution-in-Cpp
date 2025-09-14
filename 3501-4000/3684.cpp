class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> slist(s.begin(), s.end());
        sort(slist.rbegin(), slist.rend());
        if (k > slist.size()) k = slist.size();
        return vector<int>(slist.begin(), slist.begin() + k);
    }
};
