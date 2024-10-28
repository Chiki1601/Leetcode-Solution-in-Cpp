class Solution
{
public:
  int dfs(int d, int c, int k,vector<vector<int>> &ss,vector<vector<int>> &ts,vector<vector<int>> &m){
    if (d == k)return 0;

    if (m[d][c] != -1) return m[d][c];

    int maxPoints = ss[d][c] + dfs(d + 1, c, k, ss, ts, m);

    for (int n = 0; n < ts.size(); n++){

      if (n != c)
         maxPoints = max(maxPoints, ts[c][n] + dfs(d + 1, n, k, ss, ts, m));

    }
    return m[d][c] = maxPoints;
  }

  int maxScore(int n, int k,vector<vector<int>> &ss,vector<vector<int>> &ts){

    vector<vector<int>> m(k, vector<int>(n, -1));

    int maxPoints = 0;

    for (int s = 0; s < n; s++)
      
        maxPoints = max(maxPoints, dfs(0, s, k, ss, ts, m));

    return maxPoints;
  }
};
