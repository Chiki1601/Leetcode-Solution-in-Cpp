class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

        int n=nums2.size();
        int block=sqrt(n);
        int sz=block;
        vector<long long> nums(n);
        
        
        if(block*block<n)
            sz+=2;
       
        vector<unordered_map<long long,int>> help(sz);
        vector<long long> help2(sz,0);

        for(int i=0;i<n;i++)
            {
                help[i/block][nums2[i]]++;
                nums[i]=nums2[i];
            }

        auto update=[&](int i,int j,long long val)
        {
            if(j-i+1<=2*block)
            {
                while(i <=j )
                {
                    help[i/block][nums[i]]--;
                    help[i/block][nums[i]+val]++;
                    nums[i]=nums[i]+val;
                    i++;
                }
                return ;
                
            }
            while(i%block !=0 )
                {
                    help[i/block][nums[i]]--;
                    help[i/block][nums[i]+val]++;
                    nums[i]=nums[i]+val;
                    i++;
                }
            while(j%block != block-1)
                {
                    help[j/block][nums[j]]--;
                    help[j/block][nums[j]+val]++;
                    nums[j]=nums[j]+val;
                    j--;
                }
            while((i/block)<=(j/block))
                {
                    help2[i/block]+=val;
                    i+=block;
                }
            return ;
        };

        auto queryAns=[&](int val){
            int ans=0;
            int i=0;
            while(i<sz)
                {
                    ans+=help[i][val-help2[i]];
                    i++;
                }
            return ans;
            
        };
        vector<int> ans;

        for(auto &query:queries)
            {
                if(query[0]==1)
                {
                    int i=query[1],j=query[2],val=query[3];

                    if(n>100)
                    update(i,j,val);
                    else{
                        while(i <=j )
                            {
                                help[i/block][nums[i]]--;
                                help[i/block][nums[i]+val]++;
                                nums[i]=nums[i]+val;
                                i++;
                            }
                        
                    }
                }
                else{
                    int anscur=0;
                    for(auto num:nums1)
                        {
                            anscur+=queryAns(query[1]-num);
                            
                        }
                    ans.push_back(anscur);
                    
                }
                
            }
        return ans;
        
    }
};
