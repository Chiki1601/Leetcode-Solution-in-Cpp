class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        vector<int>pfixMax(n),sfixMin(n);
        pfixMax[0]=nums[0];
        sfixMin[n-1]=nums[n-1];
        for(int i=1;i<n;i+=1){
            pfixMax[i]=max(nums[i],pfixMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            sfixMin[i]=min(sfixMin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int Score=pfixMax[i]-sfixMin[i];
            if(Score <= k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
