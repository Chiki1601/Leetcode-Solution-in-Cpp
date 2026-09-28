class Solution {
public:

    bool check_two_sum(vector<int>&nums,int i,int j){
        vector<int>f(501,0);


        for(int l=i;l<=j;l++){
            f[nums[l]]++;
        }
        
        for(int l=1;l<=500;l++){
            if(f[l] <= 0){
                continue;
            }
            f[l]--;
            for(int k=1;k<=500;k++){
                if(f[k] <= 0){
                    continue;
                }
                f[k]--;

                int val = l + k;

                if(val <= 500 && f[val] > 0){return true;}

                f[k]++;
                
            }

            f[l]++;
        }
        return false;
    }

    
    int maxSubarray(vector<int>& nums) {

        int n = nums.size();
    
        int l = 0;
        int r = 2;
        int ans = min(2,n);

        while(r < n){
            if(check_two_sum(nums,l,r)){
                l++;
                r++;
            }else{
                ans = max(ans,r-l+1);
                r++;
            }
        }

        return ans;
        
    }
};
