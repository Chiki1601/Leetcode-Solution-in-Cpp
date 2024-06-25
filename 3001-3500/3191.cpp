class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 2, ans = 0;
        while(j < n){
            if(nums[i] == 0){
                ans++;
                for(int k = i; k < i + 3; k++){
                    nums[k] = nums[k] == 0 ? 1 : 0;
                }
            }
            i++, j++;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) return -1;
        }
        return ans;
    }
};
