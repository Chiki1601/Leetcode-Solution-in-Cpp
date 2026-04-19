#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MX = 50005;
int F[MX][6], C[MX], init = []{
    for (int i = 2; i < MX; i++)
        if (!C[i]) for (int j = i; j < MX; j += i) F[j][C[j]++] = i;
    return 0;
}();

class Solution {
public:
    int countGoodSubseq(vector<int>& A, int P, vector<vector<int>>& Q) {
        int N = A.size(), act = 0, ans = 0, pf[MX]={}, ff[MX]={}, S[MX]={};
        if (N == 1) return 0;

        for (int i = P; i < MX; i += P) S[i] = i / P;

        auto mod = [&](int v, int d) {
            if (int s = S[v]) {
                for (int *p = F[s], *e = p + C[s]; p != e; ++p) {
                    ff[pf[*p]]--;
                    pf[*p] += d;
                    ff[pf[*p]]++;
                }
                act += d;
            }
        };

        for (int v : A) mod(v, 1);

        auto chk = [&]() {
            if (!act || ff[act]) return false;
            if (act < N || N >= 7) return true;
            for (int i = 0; i < N; ++i) {
                mod(A[i], -1);
                bool ok = !ff[act];
                mod(A[i], 1);
                if (ok) return true;
            }
            return false;
        };

        for (auto& q : Q) {
            mod(A[q[0]], -1);
            mod(A[q[0]] = q[1], 1);
            if (chk()) ans++;
        }
        return ans;
    }
};
