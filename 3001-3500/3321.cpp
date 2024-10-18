class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int X) {
        int n = nums.size();
        multiset<pair<long long,int>> mn; // multiset to store remaining elements
        multiset<pair<long long,int>> mx; // multiset to store top x elements and keep track of sum
        
        int i=0;
        int j= i+k-1;
        
        unordered_map<int,long long> f;
        vector<long long> ans;
        
        for(int _ = 0; _ < j; _++)
        {
            f[nums[_]]+=1;
        }
        
        long long s = 0;
        for(auto x: f)
        {
            mx.insert({x.second, x.first});
            s+= (x.second* x.first);
        }
        
        while (mx.size() > X)
        {
            mn.insert(*mx.begin());
            s-= mx.begin()->first * mx.begin()->second;
            mx.erase(mx.begin());
        }
        
        // cout<<s<<endl;
        
        while(j<n)
        {   
            if (mx.count({f[nums[j]], nums[j]}))
            {
                mx.erase(mx.find({f[nums[j]], nums[j]}));
                s-= nums[j] * f[nums[j]];
            }
            
            
            if (mn.count({f[nums[j]], nums[j]}))
                mn.erase(mn.find({f[nums[j]], nums[j]}));
            
            f[nums[j]]+=1;
            
            if (f[nums[j]] >= mx.begin()->first)
            {
                s+= nums[j] * f[nums[j]];
                mx.insert({f[nums[j]], nums[j]});
                
                mn.insert(*mx.begin());
                s-= (mx.begin()->first * mx.begin()->second);
                mx.erase(mx.begin());
            }
            else
            {
                mn.insert({f[nums[j]], nums[j]});
            }
            
            // cout<<s<<endl;
            
            if (mx.size() < X)
            {
                s+= mn.rbegin()-> first * mn.rbegin()->second;
                mx.insert(*mn.rbegin());
                mn.erase(mn.find(*mn.rbegin()));
                
            }
            
            ans.push_back(s);
            
            if (mx.count({f[nums[i]], nums[i]}))
            {
                mx.erase(mx.find({f[nums[i]], nums[i]}));
                s-= nums[i] * f[nums[i]];
            }
            
            if (mn.count({f[nums[i]], nums[i]}))
                mn.erase(mn.find({f[nums[i]], nums[i]}));
            
            
            f[nums[i]]-=1;
            
            
            if (f[nums[i]] >= mx.begin()->first)
            {
                s+= nums[i] * f[nums[i]];
                mx.insert({f[nums[i]], nums[i]});
                
                mn.insert(*mx.begin());
                s-= (mx.begin()->first * mx.begin()->second);
                mx.erase(mx.begin());
            }
            else
            {
                mn.insert({f[nums[i]], nums[i]});
            }
            
            if (mx.size() < X)
            {
                s+= mn.rbegin()-> first * mn.rbegin()->second;
                mx.insert(*mn.rbegin());
                mn.erase(mn.find(*mn.rbegin()));
            }
            
            i+=1;
            j+=1;
            
        }
        
        return ans;
    }
};
