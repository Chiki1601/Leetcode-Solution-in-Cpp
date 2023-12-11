class Solution {
    long pow(long base, long exp, long mod) {
        long ans = 1;
        while (exp > 0) {
            if (exp & 1) ans = ans * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return ans;
    }
public:
    int numberOfGoodPartitions(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size(), ans = 0, cnt = 0;
        typedef array<int, 2> PII; // index intervals {first, last}
        vector<PII> v; // array of intervals
        unordered_map<int, int> F, L; // mapping from A[i] to the index of its first/last occurrence
        for (int i = 0; i < N; ++i) {
            if (F.count(A[i]) == 0) F[A[i]] = i;
            L[A[i]] = i;
        }
        for (auto &[n, f] : F) v.push_back({f, L[n]});
        sort(begin(v), end(v)); // Sort intervals in ascending order
        int E = -1;
        for (auto &[begin, end] : v) { // Count of number of non-overlapping intervals
            if (begin > E) ++cnt;
            E = max(E, end);
        }
        return pow(2, cnt - 1, mod); // If there are `cnt` non-overlapping intervals, there are `2^{cnt-1}` ways to split the array.
    }
};
