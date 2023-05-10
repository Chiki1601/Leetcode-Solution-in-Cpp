class Solution {
    long long make(long long x, long long y) {
        return (x << 20) | y;
    }

    void maybe(long long state, int dist, 
    priority_queue<pair<int, long long>> &q,
    unordered_map<long long, int> &d) {
        if (!d.count(state) || d[state] > dist) {
            d[state] = dist;
            q.push({-dist, state});
        }
    }
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        unordered_map<long long, vector<vector<int>>> con;
        unordered_set<long long> all = {make(target[0], target[1])};
        for (const auto& v : specialRoads) {
            con[make(v[0], v[1])].push_back({v[2], v[3], v[4]});
            all.insert(make(v[0], v[1]));
        }

        unordered_map<long long, int> d;
        unordered_set<long long> have;
        d[make(start[0], start[1])] = 0;
        priority_queue<pair<int, long long>> q;
        q.push({0, make(start[0], start[1])});
        while (!q.empty()) {
            const long long state = q.top().second;
            const int x = state >> 20, y = state & 1048575, dist = -q.top().first;
            q.pop();
            if (have.count(state)) {
                continue;
            }
            have.insert(state);
            if (x == target[0] && y == target[1]) {
                return dist;
            }
            if (con.count(state)) {
                for (const auto& v : con[state]) {
                    maybe(make(v[0], v[1]), dist + v[2], q, d);
                }
            }
            for (long long s : all) {
                maybe(s, dist + abs((s >> 20) - x) + abs((s & 1048575) - y), q, d);
            }
        }
        return -1;
    }
};
