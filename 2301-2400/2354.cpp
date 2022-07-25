class Solution {
public:
    int search(vector<int> &v,int r,int x){
        int l=0;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(v[mid]>=x){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
    long long countExcellentPairs(vector<int>& num, int k) {
        
        set<int> s;
        
        for(int i=0;i<num.size();i++){
            s.insert(num[i]);
        }
        
        vector<int> nums;
        
        for(auto x:s){
            nums.push_back(x);
        }
        
        vector<int> v;
        
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int cnt=0;
            while(n){
                n=n&(n-1);
                cnt++;
            }

            v.push_back(cnt);
        }
        
        sort(v.begin(),v.end());
        long long ans=0;
        
        for(int i=0;i<v.size();i++){
            // cout<<v[i]<<" ";
            if(v[i]>=k){
                ans+=i*2+1;
            }
            else{
                int index=search(v,i,k-v[i]);
                
                if(index!=-1)
                ans=ans+(i-index)*2+1;
            }
        }
        
        return ans;
    }
};
