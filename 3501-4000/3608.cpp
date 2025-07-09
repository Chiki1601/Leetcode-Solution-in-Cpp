class Solution {
private:
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            parent[i] = j;
            return true;
        }
        return false;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (edges.empty()) {
            return 0;
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        int count = n;
        for (const auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            if (unite(u, v)) {
                count--;
            }
            if (count < k) {
                return t;
            }
        }
        return 0;
    }
};
