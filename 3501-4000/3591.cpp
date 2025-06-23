class Solution {
public:
       bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int a : nums)
            counts[a]++;
        for (auto const& [val, c] : counts) {
            if (c == 2 || c == 3 || c == 5 || c == 7) return true;
            if (c == 1 || c % 2 == 0 || c % 3 == 0 || c % 5 == 0 || c % 7 == 0) continue;
            return true;
        }
        return false;
    }
};
