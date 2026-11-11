class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int i = 0; i < nums.size()-1; i++){
                if(nums[i] > nums[i+1]){
                    if(locked[i] == 1){
                        if(k == 0) return -1;
                        ans++;
                        locked[i] = 0;
                        k--;
                    }
                    if(locked[i+1] == 1){
                        if(k == 0) return -1;
                        ans++;
                        locked[i+1] = 0;
                        k--;
                    }
                    swap(nums[i], nums[i+1]);
                    ans++;
                }
            }
        }
        return ans;
    }
};
