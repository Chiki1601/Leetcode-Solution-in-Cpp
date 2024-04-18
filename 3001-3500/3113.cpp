class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        
         int n = nums.size();
        std::map<int, int> freqMap;
        long long count = 0;

        for (int i = 0; i < n; i++) {
            int target = nums[i];

            if (freqMap.find(target) != freqMap.end())
                count += freqMap[target];

            for (auto it : freqMap) {
                if (it.first < target)
                    freqMap.erase(it.first);
                else
                    break;
            }

            freqMap[target]++;
        }

        count += n;

        return count;
        
    }
};
