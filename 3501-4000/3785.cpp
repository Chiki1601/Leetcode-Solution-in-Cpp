class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();

        // Maps for feasibility check
        unordered_map<int, int> numsCnt;
        unordered_map<int, int> forbiddenCnt;

        for(int i = 0 ; i < n ;i++){
            numsCnt[nums[i]]++;
            forbiddenCnt[forbidden[i]]++;
        }

        // 1. Feasibility Check (Pigeonhole Principle)
        for(auto const& [num, cnt] : numsCnt){
            // If the count of a number exceeds available valid spots
            if(cnt > n - forbiddenCnt[num])
                return -1;
        }

        // 2. Count Conflicts and Find Majority Bad Element
        int totalConflicts = 0;
        int maxFreq = 0;
        unordered_map<int, int> badCnts;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == forbidden[i]){
                totalConflicts++;
                badCnts[nums[i]]++;
                maxFreq = max(maxFreq, badCnts[nums[i]]);
            }
        }

        if(totalConflicts == 0) return 0;

        // 3. Calculate Swaps
        // We try to pair up conflicts (1 swap fixes 2). 
        // We are limited by either total pairs possible OR the "majority" element constraint.
        int pairs = min(totalConflicts / 2, totalConflicts - maxFreq);

        // Total swaps = (Pairs * 1) + (Remaining * 1) 
        // This simplifies to: TotalConflicts - Pairs
        return totalConflicts - pairs;
    }
};
