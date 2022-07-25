class Solution {
public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    vector<int> seen(n);
    long long cur = 0;
    
    function<void(int)> dfs = [&](int u) {
      ++cur;
      for (int v : g[u])
        if (seen[v]++ == 0) dfs(v);      
    };
    long long ans = 0;    
    for (int i = 0; i < n; ++i) {
      if (seen[i]++) continue;
      cur = 0;
      dfs(i);
      ans += (n - cur) * cur;
    }
    return ans / 2;
  }
};
