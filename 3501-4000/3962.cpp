class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {

        int n=nums.size();

        long long ans=INT_MIN;
        if(k==0 || n==1)
        {
            long long sm=0;
            for(auto num:nums)
                {
                    sm+=num;
                    ans=max(ans,sm);
                    if(sm<0)
                        sm=0;
                }
            return ans;
        }
        int cnt=0;
        long long cur=0;
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            cur+=nums[i];
            else cnt++;
            pref[i+1]=pref[i]+nums[i];
            ans=max(ans,nums[i]*1ll);
        }
        if(cnt<=k)
        return cur;

        vector<vector<long long>> dp(n,vector<long long>(n,0));
        for(int i=0;i<n;i++)
            {
                priority_queue<int> pq;
                long long sm=0;
                for(int j=i;j<n;j++)
                    {
                        if(nums[j]>=0)
                        {
                            dp[i][j]=sm;
                            
                            continue;
                        }
                        
                        if(pq.size()<k)
                        pq.push(nums[j]),sm+=nums[j];
                        else{
                            if(pq.top()>nums[j])
                            {
                                sm-=pq.top();
                                pq.pop();
                                sm+=nums[j];
                                pq.push(nums[j]);
                            }
                        }
                        
                      
                        
                    }
                 
            }
        
        for(int i=0;i<n;i++)
            {
                priority_queue<int,vector<int>,greater<int>> pqmax;
                long long sm=0;
                for(int j=0;j<i;j++)
                    {
                        if(nums[j]<0)
                        continue;

                        if(pqmax.size()<k)
                            pqmax.push(nums[j]),sm+=nums[j];
                        else{
                            if(pqmax.top()<nums[j])
                            {
                                sm-=pqmax.top();
                                pqmax.pop();
                                sm+=nums[j];
                                pqmax.push(nums[j]);
                                
                                
                            }
                        }
                    }

                for(int j=n-1;j>i;j--)
                    {
                        long long cur=pref[j+1]-pref[i];
                        cur-=dp[i][j];
                        cur+=sm;
                        
                        ans=max(ans,cur);

                        if(nums[j]<0)
                        continue;

                        if(pqmax.size()<k)
                            pqmax.push(nums[j]),sm+=nums[j];
                        else{
                            if(pqmax.top()<nums[j])
                            {
                                sm-=pqmax.top();
                                pqmax.pop();
                                sm+=nums[j];
                                pqmax.push(nums[j]);
                            }
                        }
                        if(pqmax.size()>0)
                        ans=max(ans,sm);
 
                    }
            }
            return ans;
        
    }
};
