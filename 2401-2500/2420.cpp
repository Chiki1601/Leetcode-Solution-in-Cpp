class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> res;
        vector<int> prefix(n, 0); 
        vector<int> postfix(n, 0); 
        prefix[0] = 0;
        prefix[1] = 1;
        for(int i = 2; i < n ; i++) {
            if(nums[i - 1] <= nums[i - 2]) prefix[i] = prefix[i - 1] + 1;
            else prefix[i] = 1;
        }
        
        postfix[n - 1] = 0;
        postfix[n - 2] = 1;
        for(int i = n - 3; i >= 0 ; i--) {
            if(nums[i + 1] <= nums[i + 2]) {
                postfix[i] = postfix[i + 1] + 1;
            } else {
                postfix[i] = 1;
            }
        }
        
        for(int i = k ; i < n - k ; i++) {
            if(prefix[i] >= k && postfix[i] >= k) {
                res.push_back(i);
            }
        }
        return res;
        
    }
};
