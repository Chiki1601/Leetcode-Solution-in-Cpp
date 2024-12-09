class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            int j = i, v = nums[i];
            for (; v > 0; --v, j = (j + 1) % n);
            for (; v < 0; ++v, j = (j + n - 1) % n);
            r[i] = nums[j];
        }
        return r;
    }
};
