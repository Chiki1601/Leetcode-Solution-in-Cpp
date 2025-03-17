class Solution {
public:
    int beautifulNumbers(int l, int r) {
        long long countR = count(r);
        long long countL = count(l - 1);
        return (int)(countR - countL);
    }
    
private:
    long long count(int x) {
        if (x < 1) return 0;
        string s = to_string(x);
        int n = s.size();
        vector<int> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] = s[i] - '0';
        }
        unordered_map<string, long long> memo;
        return dp(0, true, false, false, 0, 1, digits, n, memo);
    }
    
    long long dp(int pos, bool tight, bool started, bool hasZero, int sum, int prod, const vector<int>& digits, int n, unordered_map<string, long long>& memo) {
        if (pos == n) {
            if (!started) return 0;
            if (hasZero) return 1;
            return (prod % sum == 0) ? 1 : 0;
        }
        
        string key = to_string(pos) + "_" + (tight ? "1" : "0") + "_" + (started ? "1" : "0") + "_" + (hasZero ? "1" : "0") + "_" + to_string(sum) + "_" + to_string(prod);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        long long ans = 0;
        int limit = tight ? digits[pos] : 9;
        
        if (started && hasZero && !tight) {
            long long ways = 1;
            for (int i = pos; i < n; i++) {
                ways *= 10;
            }
            memo[key] = ways;
            return ways;
        }
        
        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            if (!started) {
                if (d == 0) {
                    ans += dp(pos + 1, newTight, false, false, 0, 1, digits, n, memo);
                } else {
                    ans += dp(pos + 1, newTight, true, false, d, d, digits, n, memo);
                }
            } else {
                if (hasZero) {
                    ans += dp(pos + 1, newTight, true, true, sum + d, 0, digits, n, memo);
                } else {
                    if (d == 0) {
                        ans += dp(pos + 1, newTight, true, true, sum, 0, digits, n, memo);
                    } else {
                        ans += dp(pos + 1, newTight, true, false, sum + d, prod * d, digits, n, memo);
                    }
                }
            }
        }
        
        memo[key] = ans;
        return ans;
    }
};
