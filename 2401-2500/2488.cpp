class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // for the definision of median in this problem,
        // suppose subarray A meets the condition
        
        // there are two cases
        // 1. odd number length: median(A) == k --> {x > k} - {x < k} == 0
        // 2. even number length: median(A) == k --> {x > k} - {x < k} == 1
        
        // We need to find subarrays that contains k that meet the above two cases
        // How? We count the diff ({x > k} - {x < k}) from k for all index to its left and right
        // And we try to find the corresponding right part for all left part.
        int m = nums.size();
        int i = 0;
        for (int j = 0; j < m; ++j) {
            if (nums[j] == k) {
                i = j;
                break;
            }
        }
        
        // count of {x > k} - {x < k}
        unordered_map<int, int> left, right;
        left[0] = 1;
        right[0] = 1;
        
        int cnt = 0;
        for (int j = i-1; j >= 0; --j) {
            if (nums[j] < k) cnt--;
            else cnt++;
            left[cnt]++;
        }
        
        cnt = 0;
        for (int j = i+1; j < m; ++j) {
            if (nums[j] < k) cnt--;
            else cnt++;
            right[cnt]++;
        }
        

        int res = 0;
        for (auto &p: left) {
            // case 1
            auto it = right.find(0 - p.first);
            if (it != right.end()) res += p.second * it->second;
            
            // case 2
            it = right.find(1 - p.first);
            if (it != right.end()) res += p.second * it->second;
        }
        
        return res;
    }
};
