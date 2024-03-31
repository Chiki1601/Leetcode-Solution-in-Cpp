class Solution {
public:
   void performOrOperation(vector<int>& bitCount, int& orVal, int n){
    orVal = (orVal | n);
    for(int t = 0; t < 32; ++t) bitCount[t] += (n & (1 << t))?1:0;
}

void nullifyOrOperation(vector<int>& bitCount, int& orVal, int n){
    for(int t = 0; t < 32; ++t){
        bitCount[t] += (n & (1 << t))?-1:0;
        if(bitCount[t] == 0) orVal = orVal & (~(1<<t));
    }
}

int minimumSubarrayLength(vector<int>& nums, int k) {
    int orVal = 0, ans = INT_MAX;
    vector<int> bitCount(32, 0);
    for(int i = 0, j = 0; i < nums.size(); ++i){
        performOrOperation(bitCount, orVal, nums[i]);
        if(orVal < k) continue; 
        for( ;j <= i && orVal >= k; j++){
            nullifyOrOperation(bitCount, orVal, nums[j]);
            ans = min(ans, i - j + 1);
        }
    }
    return (ans == INT_MAX)? -1: ans;
}
};
