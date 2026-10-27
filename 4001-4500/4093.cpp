class Solution {
public:
    long rearrange(int x) {
        int dig[10] = {0}; 
        while(x > 0) {
            dig[x % 10]++; 
            x /= 10; 
        }
        long num = 0; 
        for(int i = 9; i >= 0; i--) {
            while(dig[i]) {
                num = num * 10 + i; 
                dig[i]--; 
            }
        }
        return num; 
    }
    long long maximizeSum(vector<int>& nums, int k) {
        // max sum after performing k operations. 
        vector<long> arr; 
        long long ans = 0; 
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back(rearrange(nums[i]) - nums[i]); 
            ans += nums[i]; 
        }
        sort(arr.begin(), arr.end(), greater<long>());  // sort the gain in descending order 

        int n = nums.size();  

        for(int i = 0; i < n && k > 0; i++) {
            if(arr[i] <= 0) break; 
            ans += arr[i]; // this is gain 
            k--; 
        }

        return ans; 
    }
};
