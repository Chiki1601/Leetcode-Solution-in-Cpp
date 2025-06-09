using namespace std;

static const int MAXN = 1005;
static const int INF  = 1000000000;
static int dp[MAXN][MAXN];


class Solution {
public:
    int minOperations(const string& w1, const string& w2) {
        int n = w1.size();
        const char* s1 = w1.c_str();
        const char* s2 = w2.c_str();

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = INF;
        dp[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            int base = dp[i][i];
            if (base < INF) {
                for (int j = i; j < n; ++j) {
                    int costNormal  = mininumOpr(s1, s2, i, j, false);
                    int costReverse = mininumOpr(s1, s2, i, j, true) + 1;

                    int totalMin = costNormal < costReverse ? costNormal : costReverse;
                    int candidate = base + totalMin;
                    if (candidate < dp[j+1][j+1]) {
                        dp[j+1][j+1] = candidate;
                    }
                }
            }
            for (int k = i + 1; k <= n; ++k) {
                if (dp[i][k-1] < dp[i][k]) {
                    dp[i][k] = dp[i][k-1];
                }
            }
        }

        return dp[n][n];
    }

private:
    static inline int mininumOpr(const char* a, const char* b,
                                 int i, int j, bool rev) {
        int ops = 0;
        int idxA = i;
        int idxB = rev ? j : i;
        int step = rev ? -1 : 1;
        int freq[26][26] = {};

        for (int k = i; k <= j; ++k, ++idxA, idxB += step) {
            char c1 = a[idxA];
            char c2 = b[idxB];
            if (c1 != c2) {
                int want = c1 - 'a';
                int got  = c2 - 'a';
                if (freq[got][want] > 0) {
                    --freq[got][want];
                } else {
                    ++freq[want][got];
                    ++ops;
                }
            }
        }
        return ops;
    }
};
