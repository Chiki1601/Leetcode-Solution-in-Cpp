class Solution {
public:
       int countMajoritySubarrays(vector<int>& A, int target) {
        int n = A.size(), res = 0, pre = n + 1;
        vector<int> count(2 * n + 2), acc(2 * n + 2);
        count[pre] = 1, acc[pre] = 1;
        for (int a : A) {
            pre += (a == target ? 1 : -1);
            count[pre]++;
            acc[pre] = acc[pre - 1] + count[pre];
            res += acc[pre - 1];
        }
        return res;
    }
};
