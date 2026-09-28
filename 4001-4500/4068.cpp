class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n = meetings.size();
        vector<int> by_start(n);
        vector<int> by_end(n);
        for(int i =0; i<n;++i)
        {
            by_start[i]=i;
            by_end[i]=i;
        }

        sort(by_start.begin(), by_start.end(), [&](int a, int b)
        {
            return meetings[a][0]<meetings[b][0];
        });
        sort(by_end.begin(),by_end.end(), [&](int a, int b)
        {
            return meetings[a][1]<meetings[b][1];
        });

        vector<long long>dp(n,0);
        long long max_val = -4e18;
        long long ans = 0;

        int end_ptr=0;
        for(int i =0;i<n;++i)
        {
            int cur_idx = by_start[i];
            long long s = meetings[cur_idx][0];
            long long r = meetings[cur_idx][2];

            while(end_ptr<n && meetings[by_end[end_ptr]][1]<=s)
            {
                int prev_idx= by_end[end_ptr];
                long long prev_e= meetings[prev_idx][1];
                max_val= max(max_val, dp[prev_idx]-prev_e);
                end_ptr++;
            }
            long long cur_dp = r;
            if(max_val > -2e18)
            {
                cur_dp = max(cur_dp, r+s+max_val);
            }
            dp[cur_idx]= cur_dp;
            ans= max(ans, cur_dp);
        }
        return ans;
    }
};
