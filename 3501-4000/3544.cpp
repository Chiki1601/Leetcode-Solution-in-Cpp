#define ll long long 
#define vl vector<ll>
 
#define pb push_back
#define sz(x) ((int)x.size())
#define be(x) x.begin(), x.end()


ll mod = 1e9 + 7;
ll inf = 7e18;
 
/*======================================================================================================================*/


ll find(ll curr, ll prev, ll sign, ll dist, vector<vl> &adj, vector<int> &nums,  ll k, vector<vector<vector<ll>>> &dp)
{
    
    if(dist > 50) // if dist goes above 50 make it 50 to enable memoization without overflow, as there isnt any difference between 50 and any distnce more than 50. In both cases inversion will be allowed. 
        dist = 50;
    
    if(dp[sign+1][dist+1][curr] != -1e18)
        return dp[sign+1][dist+1][curr];
    
    if(dist == -1) // no inversions done
    {
        ll a = -nums[curr];
        ll b = nums[curr];
        
        for(ll i=0; i<adj[curr].size(); ++i) // inverting
        {
            ll next = adj[curr][i];
            
            if(next != prev)
                a += find(next, curr, -1, 1, adj, nums, k, dp); // sign becomes -1, dist becomes 1.
        }
        
        for(ll i=0; i<adj[curr].size(); ++i) // not inverting
        {
            ll next = adj[curr][i];
            
            if(next != prev)
                b += find(next, curr, 0, -1, adj, nums, k, dp); // sign remains 0, dist remains -1.
        }
        
        return dp[sign+1][dist+1][curr]  = max(a, b);
    }
    
    else if(dist >= k) // inversion is allowed
    {
        ll a = -nums[curr]*sign; // -ve to get the inverted.
        ll b = nums[curr]*sign;
        
        for(ll i=0; i<adj[curr].size(); ++i) // inverting
        {
            ll next = adj[curr][i];
            
            if(next != prev)
                a += find(next, curr, sign*-1, 1, adj, nums, k, dp); // sign multiplied by -1 and dist becomes 1.
        }
        
        for(ll i=0; i<adj[curr].size(); ++i) // not inverting
        {
            ll next = adj[curr][i];
            
            if(next != prev)
                b += find(next, curr, sign, dist+1, adj, nums, k, dp); // sign unchanged, dist increased by 1.
        }
        
        return dp[sign+1][dist+1][curr]  = max(a, b);
    }
    
    else // inversion not allowed as dist < k
    {
        ll b = nums[curr]*sign;
                
        for(ll i=0; i<adj[curr].size(); ++i) // not inverting 
        {
            ll next = adj[curr][i];
            
            if(next != prev)
                b += find(next, curr, sign, dist+1, adj, nums, k, dp); // sign unchanged, dist increased by 1.
        }
        
        return dp[sign+1][dist+1][curr] = b;        
    }
    
    return 0;
}


class Solution {
public:
    long long subtreeInversionSum(vector<vector<int>>& e, vector<int>& nums, int k) {
        
        ll n = sz(e) + 1;
        vector<vl> adj(n);
        
        vector<ll> t(n+1, -1e18);
        vector<vector<ll>> tt(52, t);
        vector<vector<vector<ll>>> dp(3, tt);
        
        for(ll i=0; i<sz(e); ++i)
        {
            ll u = e[i][0];
            ll v = e[i][1];
            
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        ll ans = find(0, -1, 0, -1, adj, nums, k, dp);
        return ans;
        
    }
};
