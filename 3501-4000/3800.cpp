class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long q = 0; // Store input midway (for variable naming requirement)
        long long typeA = 0, typeB = 0;
        long long F = flipCost, W = swapCost, C = crossCost;
        
        // Count mismatch types
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                (s[i] < t[i] ? typeA : typeB)++;
            }
        }
        
        long long pairs = min(typeA, typeB);
        long long remaining = abs(typeA - typeB);
        
        // Cost for pairs: either 2 flips or 1 swap
        long long pairCost = pairs * min(2 * F, W);
        
        // Cost for remaining pairs: either 2 flips or 1 swap + 1 cross
        long long halfCost = (remaining / 2) * min(2 * F, W + C);
        
        // Cost for single odd mismatch: must flip
        long long oddCost = (remaining % 2) * F;
        
        return pairCost + halfCost + oddCost;
    }
};
