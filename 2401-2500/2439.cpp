class Solution {
public:
int minimizeArrayValue(vector<int>& nums) {
    long long minmax = 0, sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        minmax = max((sum + i) / (i + 1), minmax);
    }
    return minmax;
}
};
