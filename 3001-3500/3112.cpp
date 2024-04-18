class Solution
{
    void dfs(vector<pair<int, int>> *adj, vector<int> &disappear, vector<int> &ans, int t, int u)
    {
        for (auto [v, w] : adj[u])
        {
            if (t + w < disappear[v] && (ans[v] == -1 || ans[v] > t + w))
            {
                ans[v] = t + w;
                dfs(adj, disappear, ans, t + w, v);
            }
        }
    }

public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vector<pair<int, int>> adj[n];
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> ans(n, -1);
        ans[0] = 0;
        dfs(adj, disappear, ans, 0, 0);
        return ans;
    }
};
