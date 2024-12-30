const int INF = 1e6;
class Solution {
public:
    int makeStringGood(string s) {
        int n = s.size();
        vector<int> a(26);
        for(char c : s) {
            a[c - 'a']++;
        }
        
        int ans = n;
        for(int x : a) {
            ans = min(ans, n - x);
        }

        //The most operations needed
        for(int k = 1; k <= n; k++) { //average frequency
            vector<int> dp(26, -1);
            ans = min(ans, dfs(dp, a, k, 0));
        }
        
        return ans;
    }
    
    int dfs(vector<int>& dp, vector<int>& a, int k, int i) {
        if(i >= a.size()) {
            return 0;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        int ans = INF;
        if(a[i] >= k) {
            int more = a[i] - k;
            ans = min(ans, a[i] - k + dfs(dp, a, k, i + 1));
            if(i + 1 < a.size() && a[i + 1] <= k) {
                if(a[i + 1] + more >= k) {
                    ans = min(ans, more + dfs(dp, a, k, i + 2));
                } else {
                    //move all
                    ans = min(ans, min(more + k - (a[i + 1] + more), more + a[i + 1]) + dfs(dp, a, k, i + 2)); 
                }
            }
            
        } else {
            ans = min(ans, min(k - a[i], a[i]) + dfs(dp, a, k, i + 1));
            if(i + 1 < a.size() && a[i + 1] <= k) {
                if(a[i + 1] + a[i] >= k) {
                    ans = min(ans, a[i] + dfs(dp, a, k, i + 2));
                } else {
                    ans = min(ans, a[i] + (k - (a[i] + a[i + 1])) + dfs(dp, a, k, i + 2));
                }
            }
        }
        
        return dp[i] = ans;
    }
};
