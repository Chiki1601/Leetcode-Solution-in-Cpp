class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<pair<int, int>> pr;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= i) {
                pr.push_back({i - nums[i], nums[i]});
            }
        }
        sort(pr.begin(), pr.end());
        vector<int> temp;
        for (auto &it: pr) {
            int val = it.second;
            auto x = lower_bound(temp.begin(), temp.end(), val);
            if (x == temp.end()) {
                temp.push_back(val);
            } else {
                *x = val;
            }
        }
        return (int)temp.size();
    }
};
