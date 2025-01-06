class Solution {
public:
   int maxLength(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); ++i){
        long long gcdVal = nums[i], lcmVal = nums[i], prod = 1, maxLcm = 100000000000;
        for(int j = i; j < nums.size(); ++j){
            prod = prod*(long long)nums[j];
            if(prod > maxLcm) break;
            gcdVal = gcd(gcdVal, (long long)nums[j]);
            lcmVal = lcm(lcmVal, (long long)nums[j]);
            if(prod == gcdVal * lcmVal) ans = max(ans, j - i + 1);
        }
    }
    return ans;
}
};
