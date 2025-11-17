class Solution {
public:
    #define ll long long
    #define debug(x) cout<<#x<<" is: "<<x<<endl;
    
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        ll n = nums.size();
        vector<ll> ans;
        int last = nums[0];
        nums[0] = 1;

        // We transform nums into lengths inside block for convenience
        vector<ll> block;
        vector<pair<ll,ll>> dj;
        unordered_map<ll,ll> mp;//index-->block number
        ll bl = 0;
        mp[0] = bl;
        ll len = 1;

        // Build blocks of non-decreasing segments
        for(int i=1; i<n; i++){
            if(nums[i]>=last){
                last = nums[i];
                mp[i] = bl;
                len++;
            }else{
                block.push_back(len*(len+1)/2);
                dj.push_back({i-1-len+1,i-1});
                len = 1;
                last = nums[i];
                bl++;
                mp[i] = bl;
            }
        }
        block.push_back(len*(len+1)/2);
        dj.push_back({n-1-len+1,n-1});
        
        ll sz = block.size();
        // Prefix sum of block values
        vector<ll> pref(sz);
        pref[0] = block[0];
        for(int i=1; i<sz; i++){
            pref[i] = pref[i-1]+block[i];
        }
        // Process queries
        for(auto& x: queries){
            ll l = x[0], r = x[1];
            //block no. of l , block no. of r
            ll lb = mp[l], rb = mp[r];
            // If both inside one block
            if(lb==rb){
                ll len = r-l+1;
                ans.push_back(len*(len+1)/2);
                continue;
            }
            ll sm = 0;
            // Full blocks between them
            if(abs(lb-rb)>=2){
                //lb+1 to rb-1 ka sum       
                sm = pref[rb-1]-pref[lb];
            }
                 
            // Partial left block
            auto& xx = dj[lb];
            //l to x.second
            ll len = xx.second-l+1;
            sm += len*(len+1)/2;

            // Partial right block
            auto& y = dj[rb];
            //y.first to r
            len = r-y.first+1;
            sm += len*(len+1)/2;
            ans.push_back(sm);
        }

        return ans;
    }
};
