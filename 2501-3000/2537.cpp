class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // the number of good subarrays
        long long res = 0;
        int n = nums.size();
        // Keep track of the starting index to pop
        int srt = 0;
        // Hash map
        map <int, int> hash;
        // The number of pairs in the current subarray
        int cur = 0;
        for (int i = 0; i < n; i++) {
            // Increase the pair count  
            // Consider it this way
            // There are currently {1, 1}
            // So adding another 1 would increase the pairs by 2
            // (pair it with each of the 1s)
            cur += hash[nums[i]];
            hash [nums[i]] ++;
            // If we found a good subarray
            while (cur >= k) {
                // All subarray containing it will be good
                res += (n - i);
                // Pop from the beginning
                //  decreasing pair count in the process 
                cur -= hash[nums[srt]] - 1;
                hash[nums[srt]] --;            
                srt ++;
            }
        }
        return res;
    }
};
