class Solution {
public:
 int maxSum(vector<int>& nums) {
    int sum = 0, mx = INT_MIN;
    unordered_set<int> s;
    for(int i = 0; i < nums.size(); ++i){
        mx = max(mx, nums[i]);
        if(nums[i] <= 0 || s.find(nums[i]) != s.end()) continue;
        sum += nums[i];
        s.insert(nums[i]);
    }
    return (mx <= 0)?mx:sum;
}
};
