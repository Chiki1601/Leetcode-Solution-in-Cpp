class Solution {
public:
        int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> p(2 * n);
        iota(p.begin(), p.end(), 0);
        auto find = [&](auto self, int i) -> int {
            return p[i] == i ? i : p[i] = self(self, p[i]);
        };
        auto unite = [&](int i, int j) {
            int rootI = find(find, i);
            int rootJ = find(find, j);
            if (rootI != rootJ)
                p[rootI] = rootJ;
        };
        map<int, int> mx, my;
        int id = 0;
        for (const auto& pt : points) {
            int x = pt[0], y = pt[1];
            if (mx.find(x) == mx.end()) mx[x] = id++;
            if (my.find(y) == my.end()) my[y] = id++;
            unite(mx[x], my[y]);
        }
        map<int, int> counts;
        for (const auto& pt : points) {
            counts[find(find, mx[pt[0]])]++;
        }
        vector<int> sizes;
        for (auto const& [root, size] : counts) {
            sizes.push_back(size);
        }
        sort(sizes.rbegin(), sizes.rend());
        int res = sizes[0] + 1;
        if (sizes.size() > 1)
            res += sizes[1];
        return res;
    }
};
