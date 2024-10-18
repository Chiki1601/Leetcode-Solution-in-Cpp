class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long max = 0, sum = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            max = std::max(max, static_cast<long>(nums[i]));
            sum += max;
        }
        return sum;
    }
};
