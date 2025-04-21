class Solution {
public:
        vector<long long> resultArray(vector<int>& A, int k) {
        vector<long long> res(k, 0);
        vector<int> cnt(k, 0);
        for (int a : A) {
            vector<int> cnt2(k, 0);
            for (int i = 0; i < k; ++i) {
                cnt2[1L * i * a % k] += cnt[i];
                res[1L * i * a % k] += cnt[i];
            }
            cnt = cnt2;
            cnt[a % k]++;
            res[a % k]++;
        }
        return res;
    }
  
};
