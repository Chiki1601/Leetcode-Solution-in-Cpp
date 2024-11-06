#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size() - 1, n = moveTime[0].size() - 1;
        priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<>> heap;
        heap.push({0, 0, 0, true});
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> visited;
        while (!heap.empty()) {
            auto [time, r, c, check] = heap.top();
            heap.pop();
            if (r == m && c == n) return time;
            int newTime = check ? 1 : 2;
            for (auto& dir : directions) {
                int row = r + dir[0], col = c + dir[1];
                if (row <= m && col <= n && row >= 0 && col >= 0 && !visited.count({row, col})) {
                    heap.push({max(time, moveTime[row][col]) + newTime, row, col, !check});
                    visited.insert({row, col});
                }
            }
        }
        return -1;
    }
};
