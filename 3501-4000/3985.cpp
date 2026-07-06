class Solution {
private:
    //struct to compute rolling hashs
    struct VectorIntRollingHash {
        static const long long MOD = 1e9 + 7;
        static const long long BASE = 911382323;
        vector<long long> pref, power;
        VectorIntRollingHash(const vector<int>& v) {
            int n = v.size();
            pref.resize(n + 1, 0);
            power.resize(n + 1, 1);
            for(int i = 0; i < n; i++) {
                pref[i + 1] =
                    (pref[i] * BASE+ v[i]) % MOD;
                power[i + 1] =
                    (power[i] * BASE) % MOD;
            }
        }
        long long getHash(int l, int r) {
            long long res =
                pref[r + 1]
                - (pref[l] * power[r - l + 1]) % MOD;
            if(res < 0)
                res += MOD;
            return res;
        }
    };
public:
    long long getSum(vector<int>& nums) {
        VectorIntRollingHash rh = VectorIntRollingHash(nums);        
        reverse(nums.begin(), nums.end());
        VectorIntRollingHash rrh = VectorIntRollingHash(nums);        
        reverse(nums.begin(), nums.end());
        int n  = nums.size();
        vector<long long> pfx(n + 1, 0);
        for(int i =0 ; i < n; ++i) {
            pfx[i + 1] = pfx[i] + nums[i];
        }
        long long ans=0;
        for(int i = 0; i < n; ++i) {
            int lo = 0;
            int hi = min(i, n - i - 1);
            while(lo <= hi) {
                int mid = (hi + lo) / 2;
                int l = i - mid;
                int r = i + mid;
                int backhash = rh.getHash(l, r);
                int forwardhash = rrh.getHash(n - 1 - r, n - 1 - l);
                if(backhash == forwardhash) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            long long sum = pfx[i + lo] - pfx[i - lo + 1];  
            ans = max(ans, sum);
        }
        for(int i = 0 ;i < n - 1; ++i) {
            if(nums[i] == nums[i + 1]) {
                // even length paliindrome
                int lo = 1;
                int hi = min(i + 1, n - i - 1);
                while(lo <= hi) {
                    int mid = (hi + lo) / 2;
                    int l = i - mid + 1;
                    int r = i + mid;
                    int backhash = rh.getHash(l, r);
                    int forwardhash = rrh.getHash(n - 1 - r, n - 1 - l);
                    if(backhash == forwardhash) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                long long sum = pfx[i + lo] - pfx[i - lo + 2];
                ans = max(ans, sum);  
            }
        }
        return ans;
    }
};
