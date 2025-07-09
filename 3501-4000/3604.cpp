
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> adj(n);
        for (auto& v : edges) {
            adj[v[0]].push_back({v[1], v[2], v[3]});
        }

        vector<int> visitedTime(n, INT_MAX);
        queue<pair<int, int>> q;  // {node, current_time}
        q.push({0, 0});
        visitedTime[0] = 0;

        while (!q.empty()) {
            auto [node, currTime] = q.front();
            q.pop();

            for (auto& adjN : adj[node]) {
                int v = get<0>(adjN);
                int start = get<1>(adjN);
                int end = get<2>(adjN);

                int nextTime = max(currTime, start);

                // Only consider this edge if it's usable and it's a better time
                if (nextTime <= end && nextTime + 1 < visitedTime[v]) {
                    visitedTime[v] = nextTime + 1;
                    q.push({v, nextTime + 1});
                }
            }
        }

        return visitedTime[n - 1] == INT_MAX ? -1 : visitedTime[n - 1];
    }
};
