class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n,0),suf(n,0);
        pre[0]=nums[0];suf[n-1]=nums[n-1];
        
        vector<int> ii(n,0),dd(n,0);
        ii[0]=1;dd[n-1]=1;
        
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
            if(nums[i]>nums[i-1] && ii[i-1]){
                ii[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=nums[i]+suf[i+1];
            if(nums[i]>nums[i+1] && dd[i+1]){
                dd[i]=1;
            }
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n-1;i++){
            if(ii[i] && dd[i+1]){
                ans=min(ans,llabs(pre[i]-suf[i+1]));
            }
        }
        return ans==LLONG_MAX? -1:ans;
    }
};
