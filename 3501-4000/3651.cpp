#define FOR(i,a,b) for (int i = a ; i < b ; ++i)
class Solution {
public:
  void solve(vector<vector<int>> &curr, vector<vector<int>> &grid) {
    int n = grid[0].size(), m = grid.size();
    curr[0][0] = 0;
    FOR(i,0,m) FOR(j,0,n) {
      if (i > 0) curr[i][j] = min(curr[i][j], curr[i-1][j] + grid[i][j]);
      if (j > 0) curr[i][j] = min(curr[i][j], curr[i][j-1] + grid[i][j]);
    }
  }

  const int INF = 1e9;

  int minCost(vector<vector<int>>& grid, int k) {
    int n = grid[0].size(), m = grid.size();
    vector<vector<int>> prev(m, vector<int>(n, INF)), curr(m, vector<int>(n, INF));
    
    // Coordinate compression
    vector<int> A;
    unordered_map<int,int> MP;
    FOR(i,0,m) FOR(j,0,n) A.push_back(grid[i][j]);
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for (int i = 0, sz = A.size(); i < sz; ++i) MP[A[i]] = i;
    int sz = A.size();

    // Initial DP without teleports
    solve(prev, grid);
    int ans = prev[m-1][n-1];

    // Allow teleports one by one
    for (int t = 1; t <= k; ++t) {
      vector<int> best(sz, INF);
      curr.assign(m, vector<int>(n, INF));

      // Step 1: best for exact values
      FOR(i,0,m) FOR(j,0,n)
        best[MP[grid[i][j]]] = min(best[MP[grid[i][j]]], prev[i][j]);

      // Step 2: suffix-min to cover all >= values
      for (int i = sz - 2; i >= 0; --i)
        best[i] = min(best[i], best[i+1]);

      // Step 3: update with teleport landing
      FOR(i,0,m) FOR(j,0,n)
        curr[i][j] = min(prev[i][j], best[MP[grid[i][j]]]);

      // Step 4: spread via normal moves
      solve(curr, grid);

      prev.swap(curr);
      ans = prev[m-1][n-1];
    }
    return ans;
  }
};
