class Solution {
public:
    long long minPenalty(int n, int start, vector<int>& requests) {
        vector<int> L, R;
        for (int r : requests) {
            if (r < start) L.push_back(r);
            else if (r > start) R.push_back(r);
        }

        sort(L.rbegin(), L.rend());
        sort(R.begin(), R.end());

        int p = L.size(), q = R.size();
        vector<long long> d(p + 1), e(q + 1);
        d[0] = 0;
        for (int i = 1; i <= p; i++) d[i] = start - L[i - 1];
        e[0] = 0;
        for (int j = 1; j <= q; j++) e[j] = R[j - 1] - start;

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> S0(p + 1, vector<long long>(q + 1, INF));
        vector<vector<long long>> T0(p + 1, vector<long long>(q + 1, 0));
        vector<vector<long long>> S1(p + 1, vector<long long>(q + 1, INF));
        vector<vector<long long>> T1(p + 1, vector<long long>(q + 1, 0));

        S0[0][0] = S1[0][0] = 0;

        for (int i = 0; i <= p; i++) {
            for (int j = 0; j <= q; j++) {
                if (i == 0 && j == 0) continue;
                long long K = (p - i) + (q - j);

                if (i >= 1) {
                    long long bestS = INF, bestT = 0;

                    if (S0[i - 1][j] < INF) {
                        long long step = d[i] - d[i - 1];
                        long long T = T0[i - 1][j] + step;
                        long long S = S0[i - 1][j] + T;
                        if (S + K * T < bestS + K * bestT) {
                            bestS = S;
                            bestT = T;
                        }
                    }

                    if (j >= 1 ? S1[i - 1][j] < INF : (i - 1 == 0)) {
                        long long baseS = (j >= 1) ? S1[i - 1][j] : 0;
                        long long baseT = (j >= 1) ? T1[i - 1][j] : 0;
                        long long step = (j >= 1 ? e[j] : 0) + d[i];
                        long long T = baseT + step;
                        long long S = baseS + T;
                        if (S + K * T < bestS + K * bestT) {
                            bestS = S;
                            bestT = T;
                        }
                    }

                    S0[i][j] = bestS;
                    T0[i][j] = bestT;
                }

                if (j >= 1) {
                    long long bestS = INF, bestT = 0;

                    if (S1[i][j - 1] < INF) {
                        long long step = e[j] - e[j - 1];
                        long long T = T1[i][j - 1] + step;
                        long long S = S1[i][j - 1] + T;
                        if (S + K * T < bestS + K * bestT) {
                            bestS = S;
                            bestT = T;
                        }
                    }

                    if (i >= 1 ? S0[i][j - 1] < INF : (j - 1 == 0)) {
                        long long baseS = (i >= 1) ? S0[i][j - 1] : 0;
                        long long baseT = (i >= 1) ? T0[i][j - 1] : 0;
                        long long step = (i >= 1 ? d[i] : 0) + e[j];
                        long long T = baseT + step;
                        long long S = baseS + T;
                        if (S + K * T < bestS + K * bestT) {
                            bestS = S;
                            bestT = T;
                        }
                    }

                    S1[i][j] = bestS;
                    T1[i][j] = bestT;
                }
            }
        }

        if (p == 0 && q == 0) return 0;

        long long ans = INF;
        if (p >= 1) ans = min(ans, S0[p][q]);
        if (q >= 1) ans = min(ans, S1[p][q]);
        return ans;
    }
};
