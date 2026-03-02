class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long res = 0;
        unordered_map<int, int> freq;
        int distinctNums = 0, validNums = 0;

        for (int r = 0, l = 0, bml = 0; r < nums.size(); r++){
            freq[nums[r]]++;
            if (freq[nums[r]] == 1) distinctNums++;
            if (freq[nums[r]] == m) validNums++;

            while (distinctNums > k){
                if (l >= bml) {            
                    
                    freq[nums[l]]--;
                    if (freq[nums[l]] == 0) distinctNums--;
                    if (freq[nums[l]] == m - 1) validNums--;
                }
                l++;
                bml = max(bml, l); 
            }
            if (distinctNums == k && validNums == k){
           

                while (freq[nums[bml]] > m){ 
                    freq[nums[bml]]--;
                   bml++;
                }
                res += bml - l + 1;
            }
        }
        return res;
    }
};
