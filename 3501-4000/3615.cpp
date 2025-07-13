int res = 0;
bool dp[16384] = {};
void dfs(int i, int j, vector<unordered_set<int>>& al, const string& l, uint mask, vector<bool> &visited) {
    mask |= (1 << i) | (1 << j);
    if (exchange(dp[mask], true))
        return;
    visited[i] = visited[j] = true;
    res = max(res, popcount(mask));
    for (int x : al[i])
        if (!visited[x])
            for (int y : al[j])
                if (!visited[y] && x != y && l[x] == l[y])
                    dfs(x, y, al, l, mask, visited);
    visited[i] = visited[j] = false;
}
int maxLen(int n, vector<vector<int>>& edges, string label) {
    vector<unordered_set<int>> al(n);
    for (const auto& e : edges) {
        al[e[0]].insert(e[1]);
        al[e[1]].insert(e[0]);
    }
    for (int i = 0; i < n; ++i) {
        dfs(i, i, al, label, 0, vector<bool>(n) = {});
        for (int j : al[i])
            if (i < j && label[i] == label[j])
                dfs(i, j, al, label, 0, vector<bool>(n) = {});
    }
    return res;
}
