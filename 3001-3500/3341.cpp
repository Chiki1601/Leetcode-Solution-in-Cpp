
class Solution {
public:
    int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> minHeap;
        std::vector<std::vector<int>> time(rows, std::vector<int>(cols, INT_MAX));
        
        minHeap.emplace(0, 0, 0); // time, x, y
        time[0][0] = 0;

        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!minHeap.empty()) {
            auto [currentTime, x, y] = minHeap.top();
            minHeap.pop();

            if (x == rows - 1 && y == cols - 1) {
                return currentTime;
            }

            for (const auto& [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    int waitTime = std::max(moveTime[newX][newY] - currentTime, 0);
                    int newTime = currentTime + 1 + waitTime;

                    if (newTime < time[newX][newY]) {
                        time[newX][newY] = newTime;
                        minHeap.emplace(newTime, newX, newY);
                    }
                }
            }
        }

        return -1; // unreachable
    }
};
