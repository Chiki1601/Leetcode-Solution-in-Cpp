class Solution {
public:
    long long solve(int i , int parity , int del , vector<int>& nums ,
                    vector<vector<vector<long long>>>& dp) {

        if(i == nums.size()) return 0 ;

        if(dp[i][parity][del] != LLONG_MIN) return dp[i][parity][del] ;

        long long ans = 0 ;

        long long val ;

        if(parity == 0) {
            val = nums[i] ;
        }
        else {
            val = -1LL * nums[i] ;
        }

        int nextParity = 1 - parity ;

        // Take current element
        long long take = val + solve(i + 1 , nextParity , del , nums , dp) ;
        ans = max(ans , take) ;

        // Delete current element
        if(del == 0) {
            long long skip = solve(i + 1 , parity , 1 , nums , dp) ;
            ans = max(ans , skip) ;
        }

        return dp[i][parity][del] = ans ;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ;

        vector<vector<vector<long long>>> dp(
            n + 1 ,
            vector<vector<long long>>(2 , vector<long long>(2 , LLONG_MIN))
        ) ;

        long long ans = LLONG_MIN ;

        int i = 0 ;

        while(i < n) {
            long long curr = nums[i] + solve(i + 1 , 1 , 0 , nums , dp) ;
            ans = max(ans , curr) ;
            i++ ;
        }

        return ans ;
    }
};
