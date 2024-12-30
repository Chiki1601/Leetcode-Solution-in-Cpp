#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int value : nums) {
            countMap[value]++;
        }

        int totalDuplicates = 0;
        for (auto& entry : countMap) {
            if (entry.second > 1) {
                totalDuplicates += entry.second - 1;
            }
        }

        int operationCount = 0;
        while (totalDuplicates > 0) {
            if (nums.size() >= 3) {
                nums = vector<int>(nums.begin() + 3, nums.end());
            } else {
                nums.clear();
            }
            
            countMap.clear();
            for (int value : nums) {
                countMap[value]++;
            }
            
            totalDuplicates = 0;
            for (auto& entry : countMap) {
                if (entry.second > 1) {
                    totalDuplicates += entry.second - 1;
                }
            }
            operationCount++;
        }
        return operationCount;
    }
};
