class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> t;
        t.reserve(nums.size());
        for (int x : nums) if (x >= 0) t.push_back(x);
        if (t.empty()) return nums;
        k %= t.size();
        rotate(t.begin(), t.begin() + k, t.end());
        int j = 0;
        for (int& x : nums) {
            if (x >= 0) x = t[j++];
        }
        return nums;
    }
};
