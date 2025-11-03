class Solution {
public:
    using ll = long long;
    using i128 = __int128_t;
    long long minimumTime(vector<int>& d, vector<int>& r) {

        ll low = 0, high = LLONG_MAX;
        ll temp = (i128)(d[0] + d[1]) * (i128)max(r[0], r[1]);
        high = max(100LL, min(high, temp));
        ll time = 0;

        while (low <= high) {

            ll mid = low + (high - low) / 2;
            ll x1 = mid - mid / r[0]; // drone 1 vacancies
            ll x2 = mid - mid / r[1]; // drone 2 vacancies
            ll gcdd = gcd(r[0], r[1]);
            i128 x = (i128)(r[0]/gcdd) * (i128)r[1];
            // overlapping time
            ll x3 = mid - (mid / r[0] + mid/r[1] - mid/x);

            if (x1 >= d[0] and x2 >= d[1] and x1 + x2 - x3 >= d[0] + d[1]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
