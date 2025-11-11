class Solution {
public:
      long long countMajoritySubarrays(vector<int>& A, int target) {
        int n = A.size(), pre = n + 1;
        vector<long long> count(2 * n + 2), acc(2 * n + 2);
        long long res = 0;
        count[pre] = acc[pre] = 1;
        for (int a : A) {
            pre += (a == target ? 1 : -1);
            acc[pre] = ++count[pre] + acc[pre - 1];
            res += acc[pre - 1];
        }
        return res;
    }
};
