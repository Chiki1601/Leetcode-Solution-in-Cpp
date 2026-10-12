class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int,int>val;
        vector<int>ans={-1,-1};
        long long p_max = -1e18;
        for(int j =0; j<nums.size();++j)
        {
            int x = nums[j], comp = target-x;
            if(val.count(comp))
            {
                if(x>comp)
                {
                    long long prod = (long long)x*comp;
                    if(prod>p_max)
                    {
                        p_max = prod;
                        ans = {j, val[comp]};
                    }
                }
                if(comp>x)
                {
                    long long prod = (long long)comp * x;
                    if(prod >p_max)
                    {
                        p_max = prod;
                        ans = {val[comp], j};
                    }
                }
            }
               
            
            if(!val.count(x))
            {
                val[x]=j;
            }
        }
        return ans;
    }
};
