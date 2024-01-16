class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        // Step 1: Frequency Calculation
        std::unordered_map<int, int> um;
        for (int x : nums) {
            um[x]++;
        }

        // Step 2: Find Maximum Frequency
        int maxi = 0;
        for (auto x : um) {
            if (x.second > maxi) {
                maxi = x.second;
            }
        }

        // Step 3: Calculate Total Frequency with Maximum Frequency
        int ans = 0;
        for (auto x : um) {
            if (x.second == maxi) {
                ans += maxi;
            }
        }

        // Step 4: Return Result
        return ans;
    }
};
