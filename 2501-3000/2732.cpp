class Solution {
public:
  vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
    // This is actually the $2^k$ we mentioned in above explanation.
    // It is NOT the $N$ we mentioned.
    const int N = 1 << grid[0].size();
    vector<int> first_index(N, -1);
    for (int i = grid.size() - 1; i >=0; --i) {
      first_index[Encode(grid[i])] = i;
    }
    if (first_index[0] != -1) {
      // We got a 0 row.
      return {first_index[0]};
    }

    for (int a = 1; a < N; ++a) {
      if (first_index[a] == -1) continue;
      for (int b = a + 1; b < N; ++b) {
        if (first_index[b] == -1) continue;
        if ((a & b) == 0) {
          // We found a valid pair.
          int ra = first_index[a];
          int rb = first_index[b];
          return {min(ra, rb), max(ra, rb)};
        }
      }
    }
    return {};
  }
  
  static uint Encode(const vector<int>& row) {
    uint x = 0;
    for (int i = 0; i < row.size(); ++i) {
      if (row[i] == 0) continue;
      x |= 1 << i;
    }
    return x;
  }
};
