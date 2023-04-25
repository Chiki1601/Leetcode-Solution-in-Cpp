class Solution {
public:
   int minimumVisitedCells(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<set<int>> s0(m), s1(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            s0[i].insert(j);
            s1[j].insert(i);
        }
    }
    queue<vector<int>> q;
    q.push({0, 0, 1});

    while (!q.empty()) {
        auto cell = q.front(); q.pop();
        int i = cell[0], j = cell[1], d = cell[2];
        if (i == m - 1 && j == n - 1) return d;

        auto it = s0[i].lower_bound(j + 1);
        while (it != s0[i].end() && *it <= j + grid[i][j]) {
            q.push({i, *it, d + 1});
            s1[*it].erase(i);
            s0[i].erase(it++);
        }
        it = s1[j].lower_bound(i + 1);
        while (it != s1[j].end() && *it <= i + grid[i][j]) {
            q.push({*it, j, d + 1});
            s0[*it].erase(j);
            s1[j].erase(it++);
        }
    }
    return -1;
}
};
