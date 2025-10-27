class Solution {
public:
    long long countStableSubarrays(vector<int>& v) {

        int n = v.size();
        vector<long long> pref(n);
        pref[0] = v[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (long long)v[i];
        }

        long long cnt = 0;
        map<long long, map<long long, long long>> mp;

        for (int i = 1; i < n; i++) {
            long long need = pref[i] - v[i] * 2;
            cnt += mp[need][v[i]];
            mp[pref[i-1]][v[i-1]]++;
        }

        return cnt;
    }
};
