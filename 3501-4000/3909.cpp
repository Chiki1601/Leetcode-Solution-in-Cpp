class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long a=nums[0],b=nums.back(),n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1] < nums[i]) a+=nums[i];
            else if(nums[i-1] > nums[i]) b+=nums[i-1];
        }
        if(a > b) return 0;
        else if(a < b) return 1;
        else return -1;
    }
};
