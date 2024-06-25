#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long maximumTotalDamage(std::vector<int>& power) {
        std::unordered_map<int, long long> damageFrequency;
        for (int damage : power) {
            damageFrequency[damage]++;
        }

        std::vector<int> uniqueDamages;
        for (const auto& pair : damageFrequency) {
            uniqueDamages.push_back(pair.first);
        }
        std::sort(uniqueDamages.begin(), uniqueDamages.end());

        int totalUniqueDamages = uniqueDamages.size();
        std::vector<long long> maxDamageDP(totalUniqueDamages, 0);

        maxDamageDP[0] = uniqueDamages[0] * damageFrequency[uniqueDamages[0]];

        for (int i = 1; i < totalUniqueDamages; i++) {
            int currentDamageValue = uniqueDamages[i];
            long long currentDamageTotal = currentDamageValue * damageFrequency[currentDamageValue];

            maxDamageDP[i] = maxDamageDP[i - 1];

            int previousIndex = i - 1;
            while (previousIndex >= 0 && 
                   (uniqueDamages[previousIndex] == currentDamageValue - 1 || 
                    uniqueDamages[previousIndex] == currentDamageValue - 2 || 
                    uniqueDamages[previousIndex] == currentDamageValue + 1 || 
                    uniqueDamages[previousIndex] == currentDamageValue + 2)) {
                previousIndex--;
            }

            if (previousIndex >= 0) {
                maxDamageDP[i] = std::max(maxDamageDP[i], maxDamageDP[previousIndex] + currentDamageTotal);
            } else {
                maxDamageDP[i] = std::max(maxDamageDP[i], currentDamageTotal);
            }
        }

        return maxDamageDP[totalUniqueDamages - 1];
    }
};
