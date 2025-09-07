class Solution {
public:
    static vector<int> dp;
    static bool built;

    int bit(long long num) {
        for (int i = 63; i >= 0; i--) {
            if (num & (1LL << i)) return i;
        }
        return -1;
    }
    long long makePal(long long p, int len) {
        long long pal = p;
        long long q = (len % 2 == 0) ? p : (p >> 1);
        while (q > 0) {
            pal = (pal << 1) | (q & 1);
            q >>= 1;
        }
        return pal;
    }

    int countBinaryPalindromes(long long n) {

        if (!built) {
            dp.resize(56, 0);
            dp[1] = 1; dp[2] = 1;
            for (int i = 3; i <= 55; i++) dp[i] = 2 * dp[i - 2];
            built = true;
        }

        int maxbit = bit(n);
        if (maxbit == -1) return 1; 
        int len = maxbit + 1;

        long long count = 1;
        for (int i = 1; i < len; i++) count += dp[i];

        int half = (len + 1) / 2;
        long long start = 1LL << (half - 1);
        long long end   = (1LL << half) - 1;

        long long lo = start, hi = end, best = start - 1;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            long long pal = makePal(mid, len);
            if (pal <= n) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (best >= start) count += (best - start + 1);
        return (int)count;
    }
};

vector<int> Solution::dp;
bool Solution::built = false;
