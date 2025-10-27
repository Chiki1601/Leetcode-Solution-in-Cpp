class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> squ;
        for (int i = 0; i < nums.size(); i++) {
            squ.push_back(nums[i] * nums[i]);
        }
        sort(squ.begin(), squ.end());
        int e = nums.size() - 1;
        int b = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (b > e)
                break;
            if (i % 2 == 0) {
                ans += squ[e];
                e--;
            } else {
                ans -= squ[b];
                b++;
            }
        }
        return ans;
    }
};
