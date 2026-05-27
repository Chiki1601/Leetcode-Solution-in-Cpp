class Solution {
public:
    int minOperations(vector<int>& nums) {
        int pos=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)pos=i;
        }
        bool inc=true;
        int n=nums.size(); 
        for(int i=0;i<n;i++){
            if(nums[(pos+i)%n]!=i){
                inc=false;break;
            }
        }
        if(inc){
            int op1=pos;
            int op2=n-pos+2;
            ans=min({ans,op1,op2});
        }
        bool dec=true;
         for(int i=0;i<n;i++){
             int curr=nums[i];
             int nxt=nums[(i+1)%n];
            if((nxt-curr+n)%n!=n-1){
                dec=false;break;
            }
        }
        if(dec){
            int k=n-1-pos;
            int op1=k+1;
            int op2=n-k+1;
            ans=min({ans,op1,op2});
        }
        return ans==INT_MAX?-1:ans;
    }
};
