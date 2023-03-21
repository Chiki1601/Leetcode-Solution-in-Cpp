class Solution {
public:
    long long findScore(vector<int>& nums) {
       
        int n = nums.size();
        set<pair<long long, long long>> st;
        vector<int> vis(n,0);
        for(int i = 0; i < nums.size(); i++)
        {
            st.insert({nums[i],i});
        }
        
        long long result = 0;
        
        int i = 0;
        
       for(auto x: st)
       {
           int index = x.second;
           if(vis[index] == 0)
           {
               result += x.first;
               vis[index] = 1;
               if(index - 1 >= 0) vis[index-1] = 1;
               if(index + 1 < n) vis[index + 1] = 1;
           }
       }
        
       return result; 
        

    }
};
