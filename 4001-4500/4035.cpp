class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int r=-1;r<n;r++){
            vector<int>arr;
            for(int i=0;i<n;i++){
                if(i!=r)arr.push_back(nums[i]);
            }
            int m=arr.size();if(m<=1)continue;
            vector<int>pfx(m,0);
            pfx[0]=arr[0];
            for(int i=1;i<m;i++){
                pfx[i]=gcd(pfx[i-1],arr[i]);
            }
            vector<int>sfx(m,0);
            sfx[m-1]=arr[m-1];
            for(int i=m-2;i>=0;i--)sfx[i]=gcd(sfx[i+1],arr[i]);
            int sc=0;
            for(int i=0;i<m-1;i++){
                if(pfx[i]==sfx[i+1])sc++;
            }
            ans=max(ans,sc);
        }
        return ans;
    }
};
