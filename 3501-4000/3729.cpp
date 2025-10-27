class Solution {
public:
    long long numGoodSubarrays(vector<int>& v, int k) {

        map<long long, long long> mp;
        int n = v.size();
        mp[0]++;
        long long sum = 0;
        long long cnt = 0;

        for (int i = 0; i < n;) {

            int j = i;
            long long sum2 = sum;

            while (j < n && v[j] == v[i]) {
                sum2 += (long long)v[j];
                sum2 %= k;
                cnt += mp[sum2 % k];
                j++;
            }

            j = i;
            while (i < n && v[j] == v[i]) {
                sum += v[j];
                sum %= k;
                mp[sum]++;
                i++;
            }
        }

        return cnt;
    }
};
