class Solution 
{
public:
    int longestSquareStreak(vector<int>& nums) 
    {  
        sort(nums.begin(), nums.end(), greater<int>());
        
        unordered_map<int, int> mp;
        for(auto &it:nums)
        {
            mp[it]++;
        }
        
        int count;
        int maxi=1;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            count=1;
            int x=nums[i];
            while(mp[sqrt(x)]>0)
            {
                int p=sqrt(x);
                //Since sqrt(x) can be a decimal number so we need to check  perfect square condition
                if(p*p==x) count++;
                else break;
                mp[sqrt(x)]--;
                x = sqrt(x);
            }
            maxi = max(maxi, count);
        }
        return maxi==1?-1:maxi;
    }
};
