class Solution {
public:
    int alternateDigitSum(int n) 
    {
        if(n==0) return 0;
        
        // storing the number in reverse order
        vector<int> tmp;
        while(n)
        {
            tmp.push_back(n%10);
            n/=10;
        }
        
        // reverse the number for getting the actual number
        reverse(tmp.begin(),tmp.end());
        
        int ans=0;
        bool plus=true;
        
        // do plus , minus alternatively and then return ans
        for(auto &it : tmp)
        {
            if(plus)
            {
                ans+=it;
                plus=false;
            }
            else
            {
                ans-=it;
                plus=true;
            }
        }
        return ans;
    }
};
