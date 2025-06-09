using namespace std;

class Solution {
public:
    static long long gcd(long long a, long long b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    static long long maxGCDScore(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long countGCD = 0, oddCount = 0, ongoingGCD = 0;

            for (int j = i; j < n; j++) {
                long long currentGCD = gcd(ongoingGCD, nums[j]);

                if (currentGCD != ongoingGCD) {
                    ongoingGCD = currentGCD;
                    countGCD = 1;
                } else if (nums[j] == ongoingGCD) {
                    countGCD++;
                }

                if (nums[j] % 2 != 0) {
                    oddCount++;
                }

                int len = j - i + 1;
                long long res = ongoingGCD * len;

                if (ongoingGCD % 2 != 0) {
                    if (k >= oddCount)
                        res *= 2LL;
                } else if (k >= (countGCD)) {
                    res *= 2LL;
                }

                ans = max(ans, res);
            }
        }

        return ans;
    }
};

struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;
