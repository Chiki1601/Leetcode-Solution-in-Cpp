#define ll long long

class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int N = nums.size();
        
        // Creating a prefix sum array to store cumulative sums of the elements in nums
        vector<ll> pre;
        pre.push_back(0); // Initializing with 0 as the first element
        for(auto x : nums) 
            pre.push_back((ll)x); // Converting int to ll and storing cumulative sum
        for(ll i = 1; i <= N; i++)
            pre[i] += pre[i - 1]; // Calculating cumulative sum
        
        // Using a dynamic programming approach to solve the problem
        // dp[i] stores the maximum length of a subarray ending at index i and its last element value
        
        // Initializing dp array with pair {0, 0}
        vector<pair<ll, ll>> dp(N + 1, {0, 0});
        dp[0] = {0, 0};

        for(ll i = 1; i <= N; i++) {
            auto [len, x] = dp[i - 1]; // Extracting length and last element value from previous state

            x *= -1LL; // Multiplying by -1 for comparison purposes
            
            // Comparing current element with the last element of the previous subarray
            if(x <= nums[i - 1]) {
                dp[i] = max(dp[i], {len + 1, -1LL * nums[i - 1]});
            } else {
                dp[i] = max(dp[i], {len, -1LL * (x + (ll)nums[i - 1])});
            }

            // Finding the index where the sum would be equal to lbneed using binary search
            ll lbneed = pre[i] - nums[i - 1] + x;
            ll id = lower_bound(pre.begin(), pre.end(), lbneed) - pre.begin();
            
            // Updating dp[id] if valid index is found
            if(id <= N)
                dp[id] = max(dp[id], {len + 1, -1LL * (x + pre[id] - lbneed)});
        }
        
        // Returning the maximum length of the subarray
        return dp[N].first;
    }
};

