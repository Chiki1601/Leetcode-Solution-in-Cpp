class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int x=0;
        while(true){
            auto it=max_element(nums.begin(),nums.end());
            int y=*it;
            if(y==0){
                return x;
            }x=max(x,x^y);
            for(int i=0;i<n;i++){
                nums[i]=min(nums[i],nums[i]^y);
            }
        }
    }
};
