#include <bits/stdc++.h>
using namespace std;

array<int, 4> dp[50'001][4];
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervalsO) {
        int n = intervalsO.size();
        {
            int i = 0;
            for(auto& inv : intervalsO) inv.push_back(i++);
            // pad with actual idx
            // so inv = {l, r, w, original_idx}
        }


        auto intervals = intervalsO;
        sort(intervals.begin(), intervals.end());
        

        auto better = [&](const array<int, 4>& a, const array<int, 4>& b) -> array<int, 4> {
            long long w1 = (long long) intervalsO[a[0]][2] + intervalsO[a[1]][2] + intervalsO[a[2]][2] + intervalsO[a[3]][2];
            long long w2 = (long long) intervalsO[b[0]][2] + intervalsO[b[1]][2] + intervalsO[b[2]][2] + intervalsO[b[3]][2];
            if(w1 < w2) return b;
            if(w1 > w2) return a;
            
            array<int, 4> sortedA = a, sortedB = b;
            sort(sortedA.begin(), sortedA.end());
            sort(sortedB.begin(), sortedB.end());
            if(sortedA < sortedB) return a;
            return b;
        };
        intervalsO.push_back({0, 0, 0, n});
        const array<int, 4> BLANK = {n, n, n, n};
        for(int took = 3; took >= 0; took--) {
            for(int i = n-1; i >= 0; i--) {
                // no take idx i
                const array<int, 4>& o1 = (i == n-1) ? BLANK : dp[i + 1][took];
                // take idx i
                array<int, 4> next = BLANK;
                if(took < 3) {
                    // find minimum index j
                    // such that Start of j > End of i
                    int l = i+1, r = n-1, q = -1;
                    while(l <= r) {
                        int m = (l + r) / 2;
                        if(intervals[m][0] > intervals[i][1]) {
                            q = m;
                            r = m - 1;
                        }else {
                            l = m + 1;
                        }
                    }
                    if(q != -1) {
                        next = dp[q][took + 1];
                    }
                }
                next[took] = intervals[i][3];

                dp[i][took] = better(o1, next);
            }
        }
        array<int, 4> arr = dp[0][0];
        vector<int> res;
        for(int& x : arr) {
            if(x < n) res.push_back(x);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
