typedef long long int ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        //Ignore the collisions!
        for(ll i = 0; i < s.length(); i ++)
            if(s[i] == 'L')nums[i] -= d;
            else nums[i] += d;
        // Sort according to position to calculate abs sum of each pair in O(N)
        sort(nums.begin(), nums.end());
        
        //Calculate Prefix Sum
        vector<ll> pre(nums.begin(), nums.end());
        for(ll i = 1; i < nums.size(); i++){
            pre[i] += pre[i - 1];
            pre[i] %= MOD;
        }

        ll ans = 0;
        for(ll i = 1; i < nums.size(); i++){
            // each jth index contributes to j * nums[j] - pre[j - 1]
            ans += i * nums[i] - pre[i - 1];
            ans %= MOD;
        }
        return ans;
    }
};
