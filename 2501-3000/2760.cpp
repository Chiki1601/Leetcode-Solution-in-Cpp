class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int th) {
        int n = nums.size(),maxi = 0,i = 0,j = 0,flag = 0;
        while(j < n){
            if(flag == 0){
               if(nums[j] % 2 == 0 && nums[j] <= th){
                    i = j;
                    maxi = max(maxi,j - i + 1);
                    flag = 1;
                } 
            }
            else if(flag == 1){
                int x = nums[j-1],y = nums[j],c = x + y;
                if(c % 2 && nums[j] <= th) //if we add 2 even nos or add 2 odd nos then we will always get an even number whereas if we add an odd no with an even no then we will always get an odd number
                    maxi = max(maxi,j - i + 1);
                else{
                    flag = 0;
                    j--; 
                }
            }
            j++;
        }
        return maxi;
    }
};
