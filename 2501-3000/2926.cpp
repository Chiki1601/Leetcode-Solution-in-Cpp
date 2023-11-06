class Solution {
public:
    long long get( vector<long long>&BIT,int ind)
    {
        ind++;
        long long ans =0;
        while(ind>0)
        {
            ans = max(ans,BIT[ind]);
            ind-=(ind&(-ind));
        }
        return ans;
    }
    void update(vector<long long>&BIT,int ind,long long val,int n)
    {
        ind++;
        while(ind<BIT.size())
        {
            BIT[ind] = max(val,BIT[ind]);
            ind+=(ind&(-ind));
        } 
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        vector<vector<long long >>v;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i]-i,i});
        }
        sort(v.begin(),v.end());
       
        long long ans =LLONG_MIN;
        vector<long long>BIT(n+10,0);
        for(int i=0;i<v.size();i++)
        {
            int ind = v[i][1];
            long long sum = nums[ind];
            sum+=get(BIT,ind);
            update(BIT,ind,sum,n);
            ans = max(ans,sum);  
        }
        return ans;
    }
};
