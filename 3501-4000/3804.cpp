class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), c = 0;
        auto& a = nums;
        for (int i = 0; i < n; ++i) {
            long long s = 0;
            for (int j = i; j < n; ++j) {
                s += a[j];
                for (int k = i; k <= j; ++k)
                    if (a[k] == s) {
                        c++;
                        break;
                    }
            }
        }
        return c;
    }
};
