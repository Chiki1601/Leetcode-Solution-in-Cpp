using ll = long long;
const ll NINF = (ll)-1e50;

class Solution {
private:
    ll solve(const vector<int>& A, int K) {
        int N = (int)A.size();
        vector<vector<int>> W(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            int lo = A[i], hi = A[i];
            for (int j = i; j < N; ++j) {
                lo = min(lo, A[j]);
                hi = max(hi, A[j]);
                W[i][j] = hi - lo;
            }
        }

        vector<ll> dp(N + 1, NINF);
        vector<ll> ndp(N + 1, NINF);
        dp[0] = 0;
        ll ans = 0;

        // dnc(L, R, pL, pR): compute ndp[M] for M in [L..R], arg p in [pL..min(M,pR)]
        auto dnc = [&](auto&& self, int L, int R, int pL, int pR) -> void {
            if (L > R)
                return;
            int M = (L + R) / 2;
            ll bestv = NINF;
            int bestp = pL;
            for (int p = pL; p <= M && p <= pR; ++p) {
                ll v = dp[p - 1] + (ll)W[p - 1][M - 1];
                if (v > bestv) {
                    bestv = v;
                    bestp = p;
                }
            }
            ndp[M] = bestv;
            self(self, L, M - 1, pL, bestp);
            self(self, M + 1, R, bestp, pR);
        };

        for (int i = 1; i <= K; ++i) {
            fill(begin(ndp), end(ndp), NINF);
            dnc(dnc, 1, N, 1, N);
            dp.swap(ndp);
            ans = max(ans, dp[N]);
        }
        return ans;
    }

public:
    ll maximumScore(vector<int>& A, int K) {
        int s = int(min_element(A.begin(), A.end()) - A.begin());
        rotate(A.begin(), A.begin() + s, A.end());
        ll ans = solve(A, K);
        rotate(A.begin(), A.begin() + 1, A.end());
        ans = max(ans, solve(A, K));
        return ans;
    }
};
