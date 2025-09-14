class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int> a, int k) {
        sort(begin(a), end(a));
        int n = a.size();
        vector<bool> res(n);
        bitset<4001> dp;
        dp[0] = 1;
        for(int x = 1, i = 0; x <= n; x++){
            while(i < n && a[i] < x) {
                dp |= (dp << a[i]);
                i++;
            }
            for(int sum = k; sum >= 0 && !res[x - 1] && (k - sum) / x <= n - i; sum -= x)
                if(dp[sum]) res[x - 1] = true;
        }
        return res;
    }
};
