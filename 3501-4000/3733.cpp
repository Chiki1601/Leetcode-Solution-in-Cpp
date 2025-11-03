#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool finish(long long t, vector<int>& d, vector<int>& r) {
        long long a = t - t / r[0];
        long long b = t - t / r[1];
        long long lcm = (1LL * r[0] * r[1]) / gcd(r[0], r[1]);
        long long total = t - t / lcm;
        return a >= d[0] && b >= d[1] && (long long)(d[0] + d[1]) <= total;
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long l = 0, h = 1e18;
        while (l < h) {
            long long mid = (l + h) / 2;
            if (finish(mid, d, r))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> d = {3, 2};
    vector<int> r = {2, 3};
    cout << sol.minimumTime(d, r) << endl;
}
