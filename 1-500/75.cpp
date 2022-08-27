class Solution {
public:
    void sortColors(vector<int>& nums) {
        int top = 0; 
        int bot = nums.size()-1;
        int ct1 = 0;
        int ct2 = 0;
        while (top<=bot) {
            if (nums[top] == 0) ct1++;
            if (nums[top] == 1) ct2++;            
            top++;
        }
        for (int i = 0; i <= bot; i++) {
            if (ct1-->0) nums[i] = 0;
            else if(ct2-->0) nums[i] = 1;
            else nums[i] = 2;
        }
        
    }
};
