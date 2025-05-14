using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        const int MAXV = 100000;
        long long totalRowSum = 0LL, totalColSum = 0LL;
        vector<long long> prefixRowWise(n, 0LL), prefixColWise(m, 0LL);

        static int minRow[MAXV + 1], maxRow[MAXV + 1];
        static int minCol[MAXV + 1], maxCol[MAXV + 1];
        fill(minRow, minRow + MAXV + 1, -1);
        fill(maxRow, maxRow + MAXV + 1, -1);
        fill(minCol, minCol + MAXV + 1, -1);
        fill(maxCol, maxCol + MAXV + 1, -1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = grid[i][j];
                long long val = v;
                prefixRowWise[i] += val;
                prefixColWise[j] += val;

                if (minRow[v] == -1) {
                    minRow[v] = maxRow[v] = i;
                    minCol[v] = maxCol[v] = j;
                } else {
                    minRow[v] = min(minRow[v], i);
                    maxRow[v] = max(maxRow[v], i);
                    minCol[v] = min(minCol[v], j);
                    maxCol[v] = max(maxCol[v], j);
                }
            }
        }

        for (auto r : prefixRowWise) totalRowSum += r;
        totalColSum = totalRowSum;

        long long currentRowUpperSum = 0;
        for (int i = 0; i < n - 1; ++i) {
            currentRowUpperSum += prefixRowWise[i];
            long long lowerSegmentSum = totalRowSum - currentRowUpperSum;
            if (currentRowUpperSum == lowerSegmentSum) return true;
            if (currentRowUpperSum > lowerSegmentSum) {
                long long diff = currentRowUpperSum - lowerSegmentSum;
                if (diff <= MAXV && minRow[diff] != -1) {
                    if (i == 0 || m == 1) {
                        if (diff == grid[0][0] || diff == grid[0][m - 1] || diff == grid[i][0]) return true;
                    } else if (minRow[diff] <= i) {
                        return true;
                    }
                }
            } else {
                long long diff = lowerSegmentSum - currentRowUpperSum;
                if (diff <= MAXV && maxRow[diff] != -1) {
                    if (i == n - 2 || m == 1) {
                        if (diff == grid[i + 1][0] || diff == grid[i + 1][m - 1] || diff == grid[n - 1][0]) return true;
                    } else if (maxRow[diff] > i) {
                        return true;
                    }
                }
            }
        }

        long long currentColLeftSum = 0;
        for (int j = 0; j < m - 1; ++j) {
            currentColLeftSum += prefixColWise[j];
            long long rightSegmentSum = totalColSum - currentColLeftSum;
            if (currentColLeftSum == rightSegmentSum) return true;
            if (currentColLeftSum > rightSegmentSum) {
                long long diff = currentColLeftSum - rightSegmentSum;
                if (diff <= MAXV && minCol[diff] != -1) {
                    if (j == 0 || n == 1) {
                        if (diff == grid[0][0] || diff == grid[n - 1][0] || diff == grid[0][j]) return true;
                    } else if (minCol[diff] <= j) {
                        return true;
                    }
                }
            } else {
                long long diff = rightSegmentSum - currentColLeftSum;
                if (diff <= MAXV && maxCol[diff] != -1) {
                    if (j == m - 2 || n == 1) {
                        if (diff == grid[0][j + 1] || diff == grid[n - 1][j + 1] || diff == grid[0][m - 1]) return true;
                    } else if (maxCol[diff] > j) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;
