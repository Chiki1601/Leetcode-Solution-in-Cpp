class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return nums[x] < nums[y];
        });
        int m = n;
        long long r = 0;
        for (int i = 1; i < n; ++i) {
            if (ind[i] < ind[i - 1]) {
                r += m;
                m = n - i;
            }
        }
        r += m;
        return r;
        
    }
};
