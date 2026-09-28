class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        
        // case 1 = sum % k == 0
        // case 2 = (sum-2x)%k == 0 -----> sum % k = 2x % k

        typedef long long ll;

        int n = nums.size();
        int max_len = 0;

        for( int i = 0; i < n; i++ ){

            unordered_set<int> s;
            ll curr_sum = 0;

            for( int j = i; j < n; j++ ){

                curr_sum += nums[j];

                ll remove = (((ll)2 * nums[j])%k + k) % k;
                s.insert(remove);

                ll sum = ((curr_sum % k) + k) % k;

                if( sum == 0 || s.find(sum) != s.end() ) max_len = max( max_len , j-i+1 );

            }
        }

        return max_len;

    }
};
