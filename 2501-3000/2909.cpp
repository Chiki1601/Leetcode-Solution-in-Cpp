class Solution {
public:
   int minimumSum(vector<int>& nums) {
    vector<int> smallestRight(nums.size(), nums.back());
    for(int i = nums.size()-2; i >= 0; i--){
        smallestRight[i] = min(smallestRight[i+1], nums[i]);
    }
    int smallestLeft = nums[0], ans = -1;
    for(int i = 1; i < nums.size(); i++){
        if(smallestLeft < nums[i] && smallestRight[i] < nums[i]){ 
            if(ans == -1) ans =  nums[i] + smallestRight[i] + smallestLeft;
            else ans = min(ans, nums[i] + smallestRight[i] + smallestLeft); 
        }
        smallestLeft = min(smallestLeft, nums[i]);
    }
    return ans;
}
};
