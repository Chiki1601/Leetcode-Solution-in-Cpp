
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flag=1;
        int count=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=flag){
                count++;
                flag=!flag;
            }
        }
        return count;
    }
};
