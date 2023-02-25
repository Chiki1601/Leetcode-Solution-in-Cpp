#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeviation(std::vector<int>& nums) {
        if (nums.empty()) {
            return INT_MAX;
        }

        std::priority_queue<int> evens;
        int min = INT_MAX;

        for (int num : nums) {
            if (num % 2 == 0) {
                evens.push(num);
                min = std::min(num, min);
            } else {
                evens.push(num * 2);
                min = std::min(num * 2, min);
            }
        }

        int res = INT_MAX;
        while (evens.top() % 2 == 0) {
            int max = evens.top();
            evens.pop();
            res = std::min(res, max - min);
            int newNum = max / 2;
            evens.push(newNum);
            min = std::min(min, newNum);
        }

        res = std::min(evens.top() - min, res);
        return res;
    }
};
