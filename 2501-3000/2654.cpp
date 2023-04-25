class Solution {
public:
    int minOperations(vector<int>& nums) {
        int g=0;
        int ones=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            g=__gcd(g,nums[i]);
            if(nums[i]==1)
                ones++;
        }
        
        if(g!=1)
            return -1;
        if(ones)
            return n-ones;
        
        int ans=1e9;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> nmp;
            nmp[nums[i]]=i;
            
            for(auto &[ele,r] : mp)
            {
                int val=__gcd(ele,nums[i]);
                if(nmp.find(val)==nmp.end())
                    nmp[val]=r;
                else
                    nmp[val]=std::max(nmp[val],r);
            }
                        
            if(nmp.find(1)!=nmp.end())
                ans=std::min(ans,n-1+i-nmp[1]);
            
            swap(nmp,mp);
        }
        return ans;
    }
};
