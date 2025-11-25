class Solution {
public:
    // dp[digit][tight][start][l1][l2]
    using ll = long long ;
    int n;
    string s;
    long long dp1[17][2][2][12][12], dp2[17][2][2][12][12];
    pair<ll,ll> f(int d, int tight, int start, int l1 = 11, int l2 = 11) {
        if (d == n) return {0,1LL};
        if (dp1[d][tight][start][l1][l2] != -1) return {dp1[d][tight][start][l1][l2],dp2[d][tight][start][l1][l2]};
        long long ss = 0, c = 0, l = (tight ? s[d] - '0' : 9);
        for (int i = 0; i <= l; ++i) {
            bool a = start and (!i);
            auto ans = f(d + 1,(tight) and (i == l),a,(a ? 11 : i),(a ? 11 : l1));
            if ((!start and l1 != 11 and l2 != 11) and ((l1 > l2 and l1 > i) or (l1 < l2 and l1 < i))) ss += ans.second;
            c += ans.second;
            ss += ans.first;
        }
        return {dp1[d][tight][start][l1][l2] = ss,dp2[d][tight][start][l1][l2] = c};
    }
    long long totalWaviness(long long num1, long long num2) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        s = to_string(num2);
        n = s.length();
        long long a = f(0,true,true).first;
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        s = to_string(num1 - 1);
        n = s.length();
        return a - f(0,true,true).first;
    }
};
