#define ll long long
ll dp[100002][2][2];

ll find(int pos, int stat, int sign, vector<ll> &nums)
{
    if(pos == nums.size())
        return 0;
    
    ll ans = -1e15;
    
    if(dp[pos][stat][sign]!=-1)
        return dp[pos][stat][sign];
    
    if(stat == 0) // we have to start the construction of a new subarray
        ans = max(ans, nums[pos] + find(pos+1, 1, 1, nums)); // start the construction with sign = 1 as the next element will have negetive sign
    
    else if(stat == 1) // A subarray is already under construction
    {
        if(sign == 1) // negetive sign
        {
            ans = max(ans, -nums[pos] + find(pos+1, 1, 0, nums)); // continue construction with flipped sign
            ans = max(ans,  find(pos, 0, 0, nums)); // end the construction and begin a new one at this index. Dont increase pos, just change stat to 0.
        }
    
        else if(sign == 0) // positive sign
        {
            ans = max(ans, nums[pos] + find(pos+1, 1, 1, nums)); // continue construction with flipped sign
            ans = max(ans, find(pos, 0, 0, nums));  // end the construction and begin a new one at this index. Dont increase pos, just change stat to 0.
        }
    }

    return dp[pos][stat][sign] = ans;
}

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
            
        memset(dp, -1, sizeof(dp));
        vector<ll> a(nums.begin(), nums.end()); // converted to long long just in case, to avoid overflow any kind of overflow.

        ll ans = find(0, 0, 0, a);
        return ans;
    }
};
    
