class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mult) {
        for (int i = 0; i < k; ++i) 
        {
            auto min_elem = min_element(nums.begin(), nums.end());
            *min_elem *= mult;
        }
        return nums;
    }
};
