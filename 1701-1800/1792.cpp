class Solution {
public:
    struct Node {
        int passed, all;
        bool operator <(const Node& rhs) const {
            double L = 1.0 * (all - passed) / all / (all + 1);
            double R = 1.0 * (rhs.all - rhs.passed) / rhs.all / (rhs.all + 1);
            return L > R;
        }
    };
    double maxAverageRatio(vector<vector<int>>& a, int m) {
        multiset<Node> A;
        for (auto& v : a) {
            A.insert({v[0], v[1]});
        }
        while (m--) {
            auto [x, y] = *A.begin();
            A.erase(A.begin());
            A.insert({x + 1, y + 1});
        }
        double ret = 0;
        for (auto& [x, y] : A) {
            ret += 1.0 * x / y;
        }
        ret /= a.size();
        return ret;
    }
};
