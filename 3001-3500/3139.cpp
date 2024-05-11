#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bitset>
#include <sstream>

using namespace std;
using namespace __gnu_pbds;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define sz(x) (x).size()

/* FUNCTIONS */
#define feach(el, v) for(auto &el: v)
#define rep(i, n) for(int i=0;i<n;i++)
#define reprv(i, n) for(int i=n-1;i>=0;i--)
#define reps(i, s, e) for(int i=s;i<e;i++)
#define reprve(i, e, s) for(int i=e;i>=s;i--)

#define pb push_back
#define eb emplace_back

#define dec(zz) int (zz); cin >> zz;
#define decv(zz, n) vector<int> zz(n); for(int i=0;i<n;++i) cin >> zz[i];
#define decvn(zz, n) int n; cin >> n; vector<int> zz(n); for(int i=0;i<n;++i) cin >> zz[i];

typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> oSet;

class Solution {
public:
    const ll MOD = 1e9 + 7;
    
    ll singleOpCost(ll cost1, ll cost2, int n) {
        ll ans = cost1;
        if ((n - 1) % 2 == 0) {
            ll doubleTry = (n - 3) / 2 + 2;
            doubleTry *= cost2;
            doubleTry %= MOD;
            ans = min(ans, doubleTry);
        }
        return ans;
    }

    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = sz(nums), maxVal = -1;

        if (n == 1) return 0;
        if (n == 2) {
            ll diff = abs(nums[1] - nums[0]);
            ll ans = (diff * (ll)cost1) % MOD;
            return ans;
        }

        rep(i, n) maxVal = max(maxVal, nums[i]);
        vll diffs(n);
        rep(i, n) diffs[i] = maxVal - nums[i];

        sort(diffs.begin(), diffs.end());
        ll cst1 = cost1, cst2 = cost2;
        ll singleCost = singleOpCost(cst1, cst2, n);

        if (cost1 * 2 <= cost2) {
            ll ans = 0;
            rep(i, n) {
                ans += diffs[i];
                ans %= MOD;
            }
            ans *= cst1;
            ans %= MOD;
            return (int) ans;
        } else {
            ll last = diffs[n - 1];
            ll prevSum = 0;
            rep(i, n) prevSum += diffs[i];
            prevSum -= last;

            if (last <= prevSum) {
                ll totalAm = last + prevSum;
                ll twoS = totalAm / 2, rem = totalAm % 2;

                ll twoCost = (twoS % MOD) * cst2;
                twoCost %= MOD;
                
                ll oneCost = (rem * singleCost) % MOD;
                
                ll finCost = (twoCost + oneCost) % MOD;
                return (int) finCost;
            } else {
                //case1
                ll pairs = prevSum, singles = last - prevSum;

                ll twoCost = (pairs % MOD) * cst2;
                twoCost %= MOD;

                ll oneCost = (singles % MOD) * singleCost;
                oneCost %= MOD;

                ll finCost1 = (twoCost + oneCost) % MOD;

                //case22
                ll startCost = twoCost;
                ll lastDiff = singles;

                ll secondPartCosts = 0;
                while (lastDiff > (n - 1)) {
                    ll fl = lastDiff / (n - 1), rem = lastDiff % (n - 1);
                    ll kindaCosts = (n - 1) * fl;
                    kindaCosts %= MOD;
                    kindaCosts *= cst2;
                    kindaCosts %= MOD;
                    secondPartCosts += kindaCosts;
                    lastDiff = fl + rem;
                }
                if (lastDiff == n - 1) {
                    ll hehCosts = (n - 1) * cst2;
                    hehCosts %= MOD;
                    hehCosts += singleCost;
                    
                    ll ansCost = (startCost + secondPartCosts + hehCosts) % MOD;
                    return min(ansCost, finCost1);
                } else {
                    ll hehCosts = (lastDiff + 1) * cst2;
                    hehCosts %= MOD;

                    ll remaining = (n - lastDiff - 2);
                    ll doublesRem = remaining / 2, singlesRem = remaining % 2;

                    hehCosts += ((doublesRem * cst2) % MOD);
                    hehCosts %= MOD;
                    hehCosts += ((singlesRem * singleCost) % MOD);
                    hehCosts %= MOD;

                    ll ansCost = (startCost + secondPartCosts + hehCosts) % MOD;
                    return min(ansCost, finCost1);
                }
            }
        }
    }
};
